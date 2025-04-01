#include <string>

#include "function.hpp"
#define BOOST_TEST_MODULE btest

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(btest)

BOOST_AUTO_TEST_CASE(test001) {
  BOOST_TEST_MESSAGE("Starting test001...");

  BOOST_CHECK(solution(std::string{"abcde"}, std::string{"cde"}) == true);

  BOOST_TEST_MESSAGE("Finished test001");
}

BOOST_AUTO_TEST_CASE(test002) {
  BOOST_TEST_MESSAGE("Starting test002...");
  BOOST_CHECK(solution(std::string{"abcde"}, std::string{"abc"}) == false);
}

BOOST_AUTO_TEST_CASE(test003) {
  BOOST_TEST_MESSAGE("Starting test003...");
  BOOST_CHECK(solution(std::string{"abc"}, std::string{""}) == true);
}

BOOST_AUTO_TEST_SUITE_END()