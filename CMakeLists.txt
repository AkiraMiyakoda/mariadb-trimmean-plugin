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
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror -Wno-psabi")

execute_process(COMMAND mariadb_config --cflags
    OUTPUT_VARIABLE MARIADB_INCLUDE_DIRS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
string(REPLACE "-I" "" MARIADB_INCLUDE_DIRS ${MARIADB_INCLUDE_DIRS})
string(REPLACE " " ";" MARIADB_INCLUDE_DIRS ${MARIADB_INCLUDE_DIRS})

execute_process(COMMAND mariadb_config --plugindir
    OUTPUT_VARIABLE MARIADB_PLUGIN_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

add_subdirectory(src)
