#include "cute.h"
#include "summary_listener.h"
#include "test_summary_listener.h"
#include <sstream>
#include "cute_runner.h"
#define MAKE_RUNNER_RUN_TO_OUT \
		cute::summary_listener<> listen(out);\
		cute::runner<cute::summary_listener<> > run(listen)

static void test_emptyrun() {
	std::ostringstream out;
	{
		cute::summary_listener<> listen(out);
	}
	ASSERT_EQUAL("\nUnit testing results:\nNumber of tests: 0\nSuccess: 0\nFailures: 0\nErrors: 0\n",out.str());
}
static void test_single_success(){
	std::ostringstream out;
	{
		MAKE_RUNNER_RUN_TO_OUT ;
		run(CUTE(test_emptyrun));
	}
	ASSERT_EQUAL("\nUnit testing results:\nNumber of tests: 1\nSuccess: 1\nFailures: 0\nErrors: 0\n",out.str());
}

static void test_failure() {
	throw cute::test_failure("","",42);
}

static void test_single_failure(){
	std::ostringstream out;
	{
		MAKE_RUNNER_RUN_TO_OUT ;
		run(CUTE(test_failure));
	}

	ASSERT_EQUAL("\nUnit testing results:\nNumber of tests: 1\nSuccess: 0\nFailures: 1\nErrors: 0\n",out.str());
}

static void test_summary_suite(){
	std::ostringstream out;
	{
		MAKE_RUNNER_RUN_TO_OUT;
		cute::suite suite;
		suite.push_back(CUTE(test_failure));
		suite.push_back(CUTE(test_emptyrun));
		run(suite,"test_summary_suite");
	}

	ASSERT_EQUAL("\nUnit testing results:\nNumber of tests: 2\nSuccess: 1\nFailures: 1\nErrors: 0\n",out.str());
}

static void test_error(){
	throw "oops";
}

static void test_for_error(){
	std::ostringstream out;
	{
		MAKE_RUNNER_RUN_TO_OUT ;
		run(CUTE(test_error));
	}

	ASSERT_EQUAL("\nUnit testing results:\nNumber of tests: 1\nSuccess: 0\nFailures: 0\nErrors: 1\n",out.str());
}

cute::suite make_suite_test_summary_listener(){
	cute::suite s;
	s.push_back(CUTE(test_emptyrun));
	s.push_back(CUTE(test_single_success));
	s.push_back(CUTE(test_single_failure));
	s.push_back(CUTE(test_summary_suite));
	s.push_back(CUTE(test_for_error));
	return s;
}



