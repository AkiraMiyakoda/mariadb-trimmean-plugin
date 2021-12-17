# Copyright (c) 2021 Akira Miyakoda
#
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

set(TRIMMEAN_SRC
    trimmean.cpp
)

# Create static lib and shared one from the same source for unit tests.

add_library(trimmean_plugin_static ${TRIMMEAN_SRC})
target_include_directories(trimmean_plugin_static
    PRIVATE ${MARIADB_INCLUDE_DIRS}
)

add_library(trimmean_plugin SHARED ${TRIMMEAN_SRC})
target_include_directories(trimmean_plugin
    PRIVATE ${MARIADB_INCLUDE_DIRS}
)

set_property(TARGET trimmean_plugin PROPERTY POSITION_INDEPENDENT_CODE ON)
install(TARGETS trimmean_plugin LIBRARY DESTINATION ${MARIADB_PLUGIN_DIR})
