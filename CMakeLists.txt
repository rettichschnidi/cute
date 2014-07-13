set(PROJECT_NAME "CUTE")
project(${PROJECT_NAME})
cmake_minimum_required(VERSION 2.8)

set(COMMON_FLAGS "--coverage")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMMON_FLAGS} -std=c11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_FLAGS} -std=c++11")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")

include_directories(
    cute_lib
)

add_subdirectory(cute_examples)

#enable tests
enable_testing()
add_subdirectory(cute_tests)
