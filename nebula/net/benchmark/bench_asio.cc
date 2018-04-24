#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <mutex>
#include <assert.h>
#include <vector>
#include <memory>
#include <queue>
#include <stack>
#include <thread>
#include "bench_asio.h"

io_service_pool::io_service_pool(std::size_t pool_size)
  : next_io_service_(0)
{
  if (pool_size == 0)
    throw std::runtime_error("io_service_pool size is 0");

  // Give all the io_services work to do so that their run() functions will not
  // exit until they are explicitly stopped.
  for (std::size_t i = 0; i < pool_size; ++i)
  {
    io_service_ptr io_service(new asio::io_service);
    work_ptr work(new asio::io_service::work(*io_service));
    io_services_.push_back(io_service);
    work_.push_back(work);
  }
}

void io_service_pool::run()
{
  // Create a pool of threads to run all of the io_services.
  std::vector<std::shared_ptr<std::thread> > threads;
  for (std::size_t i = 0; i < io_services_.size(); ++i)
  {
    std::shared_ptr<std::thread> thread(new std::thread(
      [i, this]() {
        io_services_[i]->run();
      }));
    threads.push_back(thread);
  }

  // Wait for all threads in the pool to exit.
  for (std::size_t i = 0; i < threads.size(); ++i)
    threads[i]->join();
}

void io_service_pool::stop()
{
  // Explicitly stop all io_services.
  for (std::size_t i = 0; i < work_.size(); ++i)
    work_[i].reset();
}

asio::io_service& io_service_pool::get_io_service()
{
  // Use a round-robin scheme to choose the next io_service to use.
  asio::io_service& io_service = *io_services_[next_io_service_];
  ++next_io_service_;
  if (next_io_service_ == io_services_.size())
    next_io_service_ = 0;
  return io_service;
}

asio::io_service& io_service_pool::get_io_service(size_t index) {
  index = index % io_services_.size();
  return *io_services_[index];
}

namespace {

  const size_t kMaxStackSize = 10;

  class session : public std::enable_shared_from_this<session>, noncopyable
  {
  public:
    session(asio::io_service& ios, size_t block_size)
      : io_service_(ios)
      , socket_(ios)
      , block_size_(block_size) {
      for (size_t i = 0; i < kMaxStackSize; ++i) {
        buffers_.push(new char[block_size_]);
      }
    }

    ~session() {
      while (!buffers_.empty()) {
        auto buffer = buffers_.top();
        delete[] buffer;
        buffers_.pop();
      }
    }

    asio::ip::tcp::socket& socket() {
      return socket_;
    }

    void start() {
      asio::ip::tcp::no_delay no_delay(true);
      socket_.set_option(no_delay);
      read();
    }

    void write(char* buffer, size_t len) {
      socket_.async_write_some(asio::buffer(buffer, len),
                               [this, self = shared_from_this(), buffer](
                                 const system::error_code& err, size_t cb) {
                                 bool need_read = buffers_.empty();
                                 buffers_.push(buffer);
                                 if (need_read && !err) {
                                   read();
                                 }
                                 if (err) {
                                   close();
                                 }
                               });
    }

    void read() {
      if (buffers_.empty()) {
        std::cout << "the cached buffer used out\n";
        return;
      }

      auto buffer = buffers_.top();
      buffers_.pop();

      socket_.async_read_some(asio::buffer(buffer, block_size_),
                              [this, self = shared_from_this(), buffer](
                                const system::error_code& err, size_t cb) {
                                if (!err) {
                                  write(buffer, cb);
                                  read();
                                } else {
                                  close();
                                }
                              });
    }
  private:
    void close() {
      socket_.close();
    }
  private:
    asio::io_service& io_service_;
    asio::ip::tcp::socket socket_;
    size_t const block_size_;
    std::stack<char*> buffers_;
  };

  class server : noncopyable
  {
  public:
    server(int thread_count, const asio::ip::tcp::endpoint& endpoint,
           size_t block_size)
      : thread_count_(thread_count)
      , block_size_(block_size)
      , service_pool_(thread_count)
      , acceptor_(service_pool_.get_io_service())
    {
      acceptor_.open(endpoint.protocol());
      acceptor_.set_option(asio::ip::tcp::acceptor::reuse_address(1));
      acceptor_.bind(endpoint);
      acceptor_.listen();
    }

    void start() {
      accept();
    }

    void wait() {
      service_pool_.run();
    }
  private:
    void accept() {
      std::shared_ptr<session> new_session(new session(
        service_pool_.get_io_service(), block_size_));
      auto& socket = new_session->socket();
      acceptor_.async_accept(socket,
                             [this, new_session = std::move(new_session)](
                               const system::error_code & err) {
                               if (!err) {
                                 new_session->start();
                                 accept();
                               }
                             });
    }
  private:
    int const thread_count_;
    size_t const block_size_;
    io_service_pool service_pool_;
    asio::ip::tcp::acceptor acceptor_;
  };

} // namespace

void server_test2(int thread_count, char const* host, char const* port,
                  size_t block_size) {
  auto endpoint = asio::ip::tcp::endpoint(
    asio::ip::address::from_string(host), atoi(port));
  server s(thread_count, endpoint, block_size);
  s.start();
  s.wait();
}




int main(int argc, char** argv) {
  server_test2(8, "127.0.0.1", "33333", 8192);
//    folly::EventBase base;
//    auto serverSocket = folly::AsyncServerSocket::newSocket(&base);
//    serverSocket->addAcceptCallback(object, &base);
//    serverSocket->setConnectionEventCallback()
//    serverSocket->bind(0);
//    serverSocket->listen(0);
//    serverSocket->startAccepting();
//
//    try {
//        serverSocket->setReusePortEnabled(true);
//    } catch (...) {
//        LOG(INFO) << "Reuse port probably not supported";
//    }
}
