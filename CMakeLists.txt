set(PROJECT_NAME "CUTE")
project(${PROJECT_NAME})
cmake_minimum_required(VERSION 3.2)

#Enable (and enforce) C++11 on all targets
set(CMAKE_CXX_STANDARD 11)
set(CXX_STANDARD_REQUIRED ON)

# Add project cmake modules to path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/coveralls/cmake)

#Import command cmake_dependent_option
include(CMakeDependentOption)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")

include_directories(
  cute_lib
)

#Add headers to QtCreator project
file(GLOB_RECURSE INCLUDES_LIST cute_lib/ cute_lib/*.h)
add_library(allincludes STATIC ${INCLUDES_LIST})
set_target_properties(allincludes PROPERTIES LINKER_LANGUAGE CXX)

#Add the CUTE nature to generated Eclipse projects
set_property(GLOBAL APPEND PROPERTY ECLIPSE_EXTRA_NATURES "ch.hsr.ifs.cute.ui.cutenature")

option(CUTE_ENABLE_GCOV "Enable GCOV on generated binaries" ON)
if(CUTE_ENABLE_GCOV)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O -g --coverage")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

#Add the examples folder
add_subdirectory(cute_examples)

#Add option to enable/disable the CUTE tests
option(CUTE_BUILD_TESTS "Build the CUTE self-tests" ON)
if(CUTE_BUILD_TESTS)
  enable_testing()
  add_subdirectory(cute_tests)
endif()

# We probably don't want this to run on every build.
cmake_dependent_option(CUTE_ENABLE_COVERALLS "Generate coveralls data" OFF "CUTE_ENABLE_GCOV;CUTE_BUILD_TESTS" OFF)
if (CUTE_ENABLE_COVERALLS)
  include(Coveralls)

  # Create the coveralls target.
  coveralls_setup("${INCLUDES_LIST}" ON)
endif()
