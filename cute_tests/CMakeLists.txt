aux_source_directory(. CUTE_TESTS_SRC)
add_executable(cute_tests ${CUTE_TESTS_SRC})

option(CUTE_CODE_COVERAGE "Calculate the code coverage of the tests." ON)
if(CUTE_CODE_COVERAGE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 --coverage")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

#Add a test which fails if CUTE detects an error
add_test(cute_tests cute_tests)
set_tests_properties(cute_tests PROPERTIES FAIL_REGULAR_EXPRESSION "#failure")
