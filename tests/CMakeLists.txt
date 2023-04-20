# Copyright (c) 2021 Akira Miyakoda
#
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

set(TESTS_SRC
  main.cpp
)

add_executable(test_runner ${TESTS_SRC})

target_compile_options(test_runner
  PRIVATE -Wall -Wextra -Wpedantic -Werror -fcompare-debug-second)

target_include_directories(test_runner
  PRIVATE ${MARIADB_INCLUDE_DIRS}
  PRIVATE ${Boost_INCLUDE_DIRS}
  PRIVATE ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(test_runner
  trimmean_plugin
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_test(test_runner COMMAND test_runner -l test_suite)
add_custom_target(check COMMAND test_runner -l test_suite)
