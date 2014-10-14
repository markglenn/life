# This adds another subdirectory, which has 'project(gtest)'.
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/gmock-1.7.0 lib)

enable_testing()

# Include googletest and googlemock
include_directories(${gtest_SOURCE_DIR}/include ${gmock_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR/lib/glm} ${CMAKE_SOURCE_DIR}/include)

set(test_SOURCE
  life/kernel_tests.cpp
  life/gametime_tests.cpp
  life/folder_archive_tests.cpp
  life/composite_archive_tests.cpp
  life/fixed_step_service_tests.cpp
)

add_executable(run_tests ${test_SOURCE})

# Link to googletest
target_link_libraries(run_tests gtest gtest_main gmock gmock_main life)

add_test(life-tests run_tests)
