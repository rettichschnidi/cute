option(CUTE_BUILD_EXAMPLES "Build the CUTE examples" TRUE)
if(CUTE_BUILD_EXAMPLES)
  add_executable(cute_example simpletest.cpp)
endif()
