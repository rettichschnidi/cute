set(PROJECT_NAME "CUTE")
project(${PROJECT_NAME})
cmake_minimum_required(VERSION 3.2)

#Enable (and enforce) C++11 on all targets
set(CMAKE_CXX_STANDARD 11)
set(CXX_STANDARD_REQUIRED ON)

#Detect whether this project is standalone or included into another CMake project
if(${PROJECT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
  set(CUTE_STANDALONE ON)
else()
  set(CUTE_STANDALONE OFF)
endif()

#Import command cmake_dependent_option
include(CMakeDependentOption)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")

#Set up target "cute" to be consumed by CUTE users
set(INCLUDES_LIST
    cute_lib/cute.h
    cute_lib/cute_base.h
    cute_lib/cute_data_driven.h
    cute_lib/cute_demangle.h
    cute_lib/cute_determine_library.h
    cute_lib/cute_determine_traits.h
    cute_lib/cute_determine_version.h
    cute_lib/cute_diff_values.h
    cute_lib/cute_listener.h
    cute_lib/cute_relops.h
    cute_lib/cute_repeated_test.h
    cute_lib/cute_suite.h
    cute_lib/cute_suite_test.h
    cute_lib/cute_test.h
    cute_lib/cute_test_incarnate.h
    cute_lib/cute_testmember.h
    cute_lib/cute_throws.h
    cute_lib/cute_version.h
    cute_lib/cute_equals.h
    cute_lib/cute_runner.h
    cute_lib/cute_to_string.h
    cute_lib/cute_xml_file.h
    cute_lib/cute_counting_listener.h
    cute_lib/ide_listener.h
    cute_lib/ostream_listener.h
    cute_lib/summary_listener.h
    cute_lib/xml_listener.h
)
add_library(cute STATIC ${INCLUDES_LIST})
set_target_properties(cute PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(cute PUBLIC cute_lib)

#Add the CUTE nature to generated Eclipse projects
set_property(GLOBAL APPEND PROPERTY ECLIPSE_EXTRA_NATURES "ch.hsr.ifs.cute.ui.cutenature")

option(CUTE_ENABLE_GCOV "Enable GCOV on generated binaries" ${CUTE_STANDALONE})
if(CUTE_ENABLE_GCOV)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O -g --coverage")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

#Add the examples folder
add_subdirectory(cute_examples)

#Add option to enable/disable the CUTE tests
option(CUTE_BUILD_TESTS "Build the CUTE self-tests" ${CUTE_STANDALONE})
if(CUTE_BUILD_TESTS)
  enable_testing()
  add_subdirectory(cute_tests)
endif()

#We probably don't want this to run on every build
cmake_dependent_option(CUTE_ENABLE_COVERALLS "Generate coveralls data" OFF "CUTE_ENABLE_GCOV;CUTE_BUILD_TESTS" OFF)
if (CUTE_ENABLE_COVERALLS)
  #Register Coveralls' CMake modules
  set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/coveralls/cmake)

  include(Coveralls)

  #Create the coveralls target
  coveralls_setup("${INCLUDES_LIST}" ON)
endif()
