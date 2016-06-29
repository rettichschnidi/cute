add_library(cute STATIC
  cute_base.h
  cute_counting_listener.h
  cute_data_driven.h
  cute_demangle.h
  cute_determine_library.h
  cute_determine_traits.h
  cute_determine_version.h
  cute_diff_values.h
  cute_equals.h
  cute.h
  cute_listener.h
  cute_relops.h
  cute_repeated_test.h
  cute_runner.h
  cute_suite.h
  cute_suite_test.h
  cute_summary_listener.h
  cute_test.h
  cute_test_incarnate.h
  cute_testmember.h
  cute_throws.h
  cute_to_string.h
  cute_version.h
  cute_xml_file.h
  ide_listener.h
  ostream_listener.h
  summary_listener.h
  xml_listener.h
)
target_include_directories(cute INTERFACE .)
set_target_properties(cute PROPERTIES LINKER_LANGUAGE CXX)

