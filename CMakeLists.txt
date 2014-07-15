set(PROJECT_NAME "CUTE")
project(${PROJECT_NAME})
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lstdc++")

include_directories(
  cute_lib
)

#Add the examples folder
add_subdirectory(cute_examples)

#Add option to enable/disable the CUTE tests
option(CUTE_BUILD_TESTS "Build the CUTE self-tests" TRUE)
if(CUTE_BUILD_TESTS)
  enable_testing()
  add_subdirectory(cute_tests)
endif()
