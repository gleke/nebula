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

#include "nebula/base/logger/glog_util.h"

#include <iostream>

#include <glog/logging.h>
#include <gflags/gflags.h>

#include <folly/Singleton.h>
#include <folly/FBString.h>

namespace {
folly::Singleton<nebula::LogInitializer> g_log_initializer;
}

namespace nebula {
    
std::shared_ptr<LogInitializer> GetLogInitializerSingleton() {
  return g_log_initializer.try_get();
}

void LogInitializer::Initialize(const char* argv0) {
  // google::InitGoogleLogging(argv0);
  // google::InstallFailureSignalHandler();
  google::SetStderrLogging(google::FATAL);
  FLAGS_stderrthreshold = google::INFO;
  // FLAGS_colorlogtostderr = true;
}

bool LogInitializer::SetConf(const std::string& conf_name, const folly::dynamic& conf) {
  std::string program_name = google::ProgramInvocationShortName() ?
                             google::ProgramInvocationShortName() : "";
  std::string logger_name;

  folly::dynamic config_data = conf;
  
  // 设置 google::FATAL 级别的日志存储路径和文件名前缀
  auto fatal_dest = config_data.get_ptr("fatal_dest");
  if (fatal_dest && fatal_dest->isString()) {
      logger_name = fatal_dest->asString() + program_name + "_fatal_";
      // std::cout << logger_name << std::endl;
      google::SetLogDestination(google::INFO, logger_name.c_str());
  }

  // 设置 google::ERROR 级别的日志存储路径和文件名前缀
  auto error_dest = config_data.get_ptr("error_dest");
  if (error_dest && error_dest->isString()) {
      logger_name = error_dest->asString() + program_name + "_error_";
      // std::cout << logger_name << std::endl;
      google::SetLogDestination(google::ERROR, logger_name.c_str());
  }

  // 设置 google::WARNING 级别的日志存储路径和文件名前缀
  auto warning_dest = config_data.get_ptr("warning_dest");
  if (warning_dest && warning_dest->isString()) {
      logger_name = warning_dest->asString() + program_name + "_warning_";
      // std::cout << logger_name << std::endl;
      google::SetLogDestination(google::WARNING, logger_name.c_str());
  }

  // 设置 google::INFO 级别的日志存储路径和文件名前缀
  auto info_dest = config_data.get_ptr("info_dest");
  if (info_dest && info_dest->isString()) {
      logger_name = info_dest->asString() + program_name + "_info_";
      // std::cout << logger_name << std::endl;
      google::SetLogDestination(google::INFO, logger_name.c_str());
  }

  auto logbufsecs = config_data.get_ptr("logbufsecs");
  if (logbufsecs && logbufsecs->isInt()) {
      FLAGS_logbufsecs = static_cast<int32_t>(logbufsecs->asInt());
  } else {
      FLAGS_logbufsecs = 10;
  }

  auto logbuflevel = config_data.get_ptr("logbuflevel");
  if (logbuflevel && logbuflevel->isInt()) {
      FLAGS_logbuflevel = static_cast<int32_t>(logbuflevel->asInt());
  } else {
      FLAGS_logbuflevel = 4;
  }

  auto max_log_size = config_data.get_ptr("max_log_size");
  if (max_log_size && max_log_size->isInt()) {
      FLAGS_max_log_size = static_cast<int32_t>(max_log_size->asInt());
  } else {
      FLAGS_max_log_size = 1000;
  }

  ///打印级别小于FLAGS_minloglevel的都不会输出到日志文件
  auto minloglevel = config_data.get_ptr("minloglevel");
  if (minloglevel && minloglevel->isInt()) {
      FLAGS_minloglevel = static_cast<int32_t>(minloglevel->asInt());
  } else {
      FLAGS_minloglevel = 0;
  }

  auto stop_logging_if_full_disk = config_data.get_ptr("stop_logging_if_full_disk");
  if (stop_logging_if_full_disk && stop_logging_if_full_disk->isBool()) {
      FLAGS_stop_logging_if_full_disk = stop_logging_if_full_disk->asBool();
  } else {
      FLAGS_stop_logging_if_full_disk = true;
  }

  auto v = config_data.get_ptr("enable_folly_debug");
  if (v && v->isBool() && v->asBool()) {
      FLAGS_v = 20;
  }
  return true;
}

}
