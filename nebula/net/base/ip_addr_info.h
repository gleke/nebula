/*
 *  Copyright (c) 2016, https://github.com/nebula-im
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

#ifndef NEBULA_NET_BASE_IP_ADDR_INFO_H_
#define NEBULA_NET_BASE_IP_ADDR_INFO_H_

#include <string>
#include <set>
#include <map>

#include <folly/Format.h>
#include <folly/DynamicConverter.h>
#include "nebula/base/stl_util.h"

struct IpAddrInfo {
  IpAddrInfo(const std::string& _addr, uint16_t _port)
  : addr(_addr)
    , port(_port) {
  }
  
  IpAddrInfo() {
    port = 0;
  }
  
  IpAddrInfo(const IpAddrInfo& other) {
    addr = other.addr;
    port = other.port;
  }
  
  void Destroy() {
    STLClearObject(&addr);
    port = 0;
  }
  
  // bool ParseFromConfigFile(const base::ConfigFile& config_file, const char* section_name);
  
  inline IpAddrInfo& operator=(const IpAddrInfo& other) {
    addr = other.addr;
    port = other.port;
    return *this;
  }
  
  bool operator==(const IpAddrInfo& other) const {
    if (addr.empty() && port!=0) {
      return false;
    }
    return addr==other.addr && port==other.port;
  }
  
  // Allows a key in STL (for example, a std::set or std::map).
  bool operator < (const IpAddrInfo& other) const {
    if( addr < other.addr ) {
      return true;
    } else if ( addr == other.addr) {
      return port < other.port;
    }
    return false;
  }
  
  std::string ToString() const {
    return folly::sformat("{{addr:{},port:{{}}", addr, port);
  }
  
  std::string addr;	// IP地址
  uint16_t port;			// 端口号
};

// TODO(@benqi): 使用反射Marsh/Unmarshal
namespace folly {
  
template <> struct DynamicConverter<IpAddrInfo> {
  static IpAddrInfo convert(const dynamic& d) {
    auto addr = convertTo<std::string>(d["addr"]);
    auto port = convertTo<uint16_t>(d["port"]);
    return IpAddrInfo(addr, port);
  }
};
  
template <> struct DynamicConstructor<IpAddrInfo, void> {
  static dynamic construct(const IpAddrInfo& x) {
    dynamic d = dynamic::object;
    d.insert("addr", x.addr);
    d.insert("port", x.port);
    return d;
  }
};
  
}

struct IpAddrInfo2 {
  IpAddrInfo2(const std::string& _addr, const std::string& _port)
  : addr(_addr)
  , port(_port) {
  }
  
  IpAddrInfo2() {
    // port = 0;
  }
  
  IpAddrInfo2(const IpAddrInfo2& other) {
    addr = other.addr;
    port = other.port;
  }
  
  void Destroy() {
    STLClearObject(&addr);
    STLClearObject(&port);
  }
  
  // bool ParseFromConfigFile(const base::ConfigFile& config_file, const char* section_name);
  
  inline IpAddrInfo2& operator=(const IpAddrInfo2& other) {
    addr = other.addr;
    port = other.port;
    return *this;
  }
  
  bool operator==(const IpAddrInfo2& other) const {
    if (addr.empty() && port.empty()) {
      return false;
    }
    return addr==other.addr && port==other.port;
  }
  
  // Allows used as a key in STL (for example, a std::set or std::map).
  bool operator < (const IpAddrInfo2& other) const {
    if( addr < other.addr ) {
      return true;
    } else if ( addr == other.addr) {
      return port < other.port;
    }
    return false;
  }
  
  std::string addr;			// IP地址
  std::string port;			// 端口号
};

typedef std::vector<IpAddrInfo> IpAddrInfoList;
typedef std::vector<IpAddrInfo2> IpAddrInfo2List;

// 集群
typedef std::map<std::string, IpAddrInfoList> ClusterAddrInfoListMap;

// typedef std::set<std::string> HostList;

#endif

