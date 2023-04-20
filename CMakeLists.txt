# Copyright (c) 2021 Akira Miyakoda
#
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

cmake_minimum_required(VERSION 3.0)

project(mariadb_trimmean_plugin)

enable_language(CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(MARIADB_PLUGIN_DIR "Plugin directory of MariaDB/MySQL")
option(BUILD_TESTS "Whether or not build unit tests")

execute_process(COMMAND mariadb_config --cflags
  OUTPUT_VARIABLE MARIADB_INCLUDE_DIRS
  OUTPUT_STRIP_TRAILING_WHITESPACE
)
string(REPLACE "-I" "" MARIADB_INCLUDE_DIRS ${MARIADB_INCLUDE_DIRS})
string(REPLACE " " ";" MARIADB_INCLUDE_DIRS ${MARIADB_INCLUDE_DIRS})

if ("${MARIADB_PLUGIN_DIR}" STREQUAL "OFF")
  message(WARNING "Option MARIADB_PLUGIN_DIR is required to install plugin")
endif()

add_subdirectory(src)

if (BUILD_TESTS)
  enable_testing()
  find_package(Boost REQUIRED COMPONENTS unit_test_framework)
  add_subdirectory(tests)
endif()
