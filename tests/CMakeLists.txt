# Copyright (c) 2021 Akira Miyakoda
#
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

set(TESTS_SRC
    main.cpp
)

add_executable(test_runner ${TESTS_SRC})
target_include_directories(test_runner
    PRIVATE ${MARIADB_INCLUDE_DIRS}
    PRIVATE ${PROJECT_SOURCE_DIR}/3rdparty/catch2
    PRIVATE ${PROJECT_SOURCE_DIR}/src
)
target_link_libraries(test_runner trimmean_plugin_static)

add_test(test_runner test_runner)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} -V DEPENDS test_runner)
