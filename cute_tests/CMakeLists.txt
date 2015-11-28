set(CUTE_TESTS_SRC
    main.cpp
    mock_listener.h
    test_cute.cpp
    test_cute_data_driven.cpp
    test_cute_data_driven.h
    test_cute_equals.cpp
    test_cute_equals.h
    test_cute_expect.cpp
    test_cute_expect.h
    test_cute_filter_runner.cpp
    test_cute_filter_runner.h
    test_cute.h
    test_cute_relops.cpp
    test_cute_relops.h
    test_cute_runner.cpp
    test_cute_runner.h
    test_cute_suite.cpp
    test_cute_suite.h
    test_cute_suite_test.cpp
    test_cute_suite_test.h
    test_cute_test.cpp
    test_cute_test.h
    test_cute_test_incarnate.cpp
    test_cute_test_incarnate.h
    test_cute_testmember.cpp
    test_cute_testmember.h
    test_cute_to_string.cpp
    test_cute_to_string_embedded.cpp
    test_cute_to_string_embedded.h
    test_cute_to_string.h
    test_repeated_test.cpp
    test_repeated_test.h
    test_summary_listener.cpp
    test_summary_listener.h
    test_xml_file_opener.cpp
    test_xml_file_opener.h
    test_xml_listener.cpp
    test_xml_listener.h
)
add_executable(cute_tests ${CUTE_TESTS_SRC})

#Add a CTest test which fails if CUTE detects a failing test
add_test(cute_tests cute_tests)
target_link_libraries(cute_tests cute)
set_tests_properties(cute_tests PROPERTIES FAIL_REGULAR_EXPRESSION "#failure")
