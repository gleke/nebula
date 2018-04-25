#  Copyright (c) 2018, https://github.com/nebulaim/nebula
#  All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

cmake_minimum_required(VERSION 2.8.7 FATAL_ERROR)

# This is necessary so that find_package can find the "Find$x.cmake" files.
# set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

# package information
set(PACKAGE_NAME      "nebula")
set(PACKAGE_VERSION   "0.11")
set(PACKAGE_STRING    "${PACKAGE_NAME} ${PACKAGE_VERSION}")
set(PACKAGE_TARNAME   "${PACKAGE_NAME}-${PACKAGE_VERSION}")
set(PACKAGE_BUGREPORT "https://github.com/nebulaim/nebula/issues")

project(${PACKAGE_NAME} C CXX)

# Check Platform Requirement
if(NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(FATAL_ERROR "nebula requires a 64bit OS")
endif()

find_package(
        Boost 1.58.0 REQUIRED
        COMPONENTS
        filesystem
        system
)

find_package(Folly REQUIRED)
find_package(GFlags REQUIRED)
find_package(Glog REQUIRED)
find_package(Threads REQUIRED)
find_package(Wangle REQUIRED)
find_package(Proxygen REQUIRED)

include(CheckFunctionExists)
include(NebulaCompilerOptions)

set(NEBULA_HOME ${CMAKE_CURRENT_SOURCE_DIR})

# set(TP_PROJECTS_DIR "nebula/third-party")
# So that qualified includes work. E.g. #include "beringei/client/$x.h"
include_directories(${NEBULA_HOME})

# So that all subsequent directories have access to
# folly, proxygen and wangle
include_directories(${FOLLY_INCLUDE_DIR} ${PROXYGEN_INCLUDE_DIR} ${WANGLE_INCLUDE_DIR})

# add_subdirectory(${TP_PROJECTS_DIR}/gtest)
# include_directories(${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})

# enable_testing()
add_subdirectory("nebula")
add_subdirectory("relay")

# modules / depends
file(GLOB NEBULA_CMAKE_FILES "cmake/*.cmake")
install(
        FILES ${NEBULA_CMAKE_FILES}
        DESTINATION cmake
        COMPONENT dev
)
