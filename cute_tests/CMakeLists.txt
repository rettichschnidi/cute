aux_source_directory(. CUTE_TESTS_SRC)
add_executable(cute_tests ${CUTE_TESTS_SRC})

#Add a test which fails if CUTE detects an error
add_test(cute_tests cute_tests)
set_tests_properties(cute_tests PROPERTIES FAIL_REGULAR_EXPRESSION "#failure")
