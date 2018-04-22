/*
 *  Copyright (c) 2016, https://github.com/nebula-im/nebula
 *  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef	NEBULA_BASE_TIMER_MANAGER_H_
#define	NEBULA_BASE_TIMER_MANAGER_H_

#include <unordered_map>
#include <mutex>

#include <folly/io/async/AsyncTimeout.h>
#include <folly/io/async/HHWheelTimer.h>
#include <folly/io/async/DelayedDestruction.h>
#include <folly/io/async/EventBase.h>
#include <folly/io/async/EventBaseManager.h>

namespace nebula {

class TimerManager {
public:
  // evb为nullptr, 则使用当前线程
	explicit TimerManager(folly::EventBase* evb = nullptr)
    : main_evb_(evb ? evb : folly::EventBaseManager::get()->getEventBase()),
      wheel_(folly::HHWheelTimer::newTimer(main_evb_)) {
  }
  ~TimerManager() = default;

  // 定时一次
  template <class F>
  void ScheduleOneShotTimeout(F fn, uint32_t timeout) {
    wheel_->scheduleTimeoutFn(fn, std::chrono::milliseconds(timeout));
  }

  // 循环定时
  // 注意，一旦启动，无法取消定时器，只能等到HHWheelTimer销毁时才会取消
  template <class F>
  void ScheduleRepeatingTimeout(F fn, uint32_t timeout) {
    class Wrapper : public folly::HHWheelTimer::Callback {
    public:
      Wrapper(TimerManager* timer_manager, F f, uint32_t t)
        : timer_manager_(timer_manager),
          fn_(std::move(f)),
          timeout_(t) {}
      
      // Impl from folly::HHWheelTimer::Callback
      void timeoutExpired() noexcept override {
        int r = 0;
        try {
          r = fn_();
        } catch (std::exception const& e) {
          LOG(ERROR) << "ScheduleRepeatingTimeout timeoutExpired callback threw an exception: "
                      << e.what();
        } catch (...) {
          LOG(ERROR) << "ScheduleRepeatingTimeout timeoutExpired callback threw a non-exception.";
        }
        
        if (r==0) {
          auto f = fn_;
          timer_manager_->ScheduleRepeatingTimeout(f, timeout_);
       }
 
        delete this;
      }
      
      void callbackCanceled() noexcept override {
        // LOG(INFO) << "ScheduleRepeatingTimeout - " << timeout_;
        try {
          // fn_();
        } catch (std::exception const& e) {
          LOG(ERROR) << "ScheduleRepeatingTimeout callbackCanceled callback threw an exception: "
                        << e.what();
        } catch (...) {
          LOG(ERROR) << "ScheduleRepeatingTimeout callbackCanceled callback threw a non-exception.";
        }
        
        // 清除
        delete this;
      }

    private:
      TimerManager* timer_manager_;
      F fn_;
      uint32_t timeout_;      // 缓存定时时间，循环调用时
    };

    Wrapper* w = new Wrapper(this, std::move(fn), timeout);
    wheel_->scheduleTimeout(w, std::chrono::milliseconds(timeout));
  }

  void cancelAll() {
    wheel_->cancelAll();
  }
  
  folly::EventBase* GetMainEventBase() {
    return main_evb_;
  }

private:
  folly::EventBase* main_evb_ {nullptr};
  folly::HHWheelTimer::UniquePtr wheel_;
};

}

#endif // NEBULA_BASE_TIMER_MANAGER_H_

