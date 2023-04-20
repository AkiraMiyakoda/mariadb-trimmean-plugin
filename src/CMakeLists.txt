# Copyright (c) 2021 Akira Miyakoda
#
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

set(TRIMMEAN_SRC
  trimmean.cpp
)

add_library(trimmean_plugin SHARED ${TRIMMEAN_SRC})
target_include_directories(trimmean_plugin
  PRIVATE ${MARIADB_INCLUDE_DIRS}
)

target_compile_options(trimmean_plugin
  PRIVATE -Wall -Wextra -Wpedantic -Werror -fcompare-debug-second)

set_property(TARGET trimmean_plugin PROPERTY POSITION_INDEPENDENT_CODE ON)
install(TARGETS trimmean_plugin LIBRARY DESTINATION ${MARIADB_PLUGIN_DIR})
