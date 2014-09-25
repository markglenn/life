# This adds another subdirectory, which has 'project(gtest)'.
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/gtest-1.7.0 lib)

enable_testing()

# Include googletest
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(test_SOURCE
  test.cpp
)

add_executable(run_tests ${test_SOURCE})

# Link to googletest
target_link_libraries(run_tests gtest gtest_main)

add_test(life-tests run_tests)
