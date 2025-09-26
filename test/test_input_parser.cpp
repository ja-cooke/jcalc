//
//  test_input_parser.cpp
//  JCalcTest
//
//  Created by Jonathan Cooke on 26/09/2025.
//

#include <boost/test/unit_test.hpp>

#include "test_fixtures.h"
#include "input_parser.h"

// All unit tests for input_parser.cpp
BOOST_AUTO_TEST_SUITE(input_parser);

BOOST_FIXTURE_TEST_CASE(empty_input_test, InputParserF)
{
  bool input_rejected = false;
  std::string input_string = "";
  
  try {
    this->operator->()->stringValid(input_string, maxCharacterLength);
  } catch (std::invalid_argument) {
    input_rejected = true;
  };
  
  BOOST_TEST(input_rejected);
}

BOOST_FIXTURE_TEST_CASE(too_long_input_test, InputParserF)
{
  bool input_rejected = false;
  std::string input_string (20,'0');
  
  try {
    this->operator->()->stringValid(input_string, maxCharacterLength);
  } catch (std::invalid_argument) {
    input_rejected = true;
  };
  
  BOOST_TEST(input_rejected);
}

BOOST_FIXTURE_TEST_CASE(reject_letters_input_test, InputParserF)
{
  bool input_rejected = false;
  std::string input_string = "b";
  
  try {
    this->operator->()->charactersInvalid(input_string);
  } catch (std::invalid_argument) {
    input_rejected = true;
  };
  
  BOOST_TEST(input_rejected);
}

BOOST_FIXTURE_TEST_CASE(reject_symbols_input_test, InputParserF)
{
  bool input_rejected = false;
  std::string input_string = "@";
  
  try {
    this->operator->()->charactersInvalid(input_string);
  } catch (std::invalid_argument) {
    input_rejected = true;
  };
  
  BOOST_TEST(input_rejected);
}

BOOST_AUTO_TEST_SUITE_END();
