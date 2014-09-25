# This adds another subdirectory, which has 'project(gtest)'.
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/gmock-1.7.0 lib)

enable_testing()

# Include googletest and googlemock
include_directories(${gtest_SOURCE_DIR}/include ${gmock_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR/lib/glm})

set(test_SOURCE
  test.cpp
)

add_executable(run_tests ${test_SOURCE})

# Link to googletest
target_link_libraries(run_tests gtest gtest_main gmock gmock_main)

add_test(life-tests run_tests)
