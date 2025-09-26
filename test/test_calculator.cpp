//
//  test_calculator.cpp
//  JCalcTest
//
//  Created by Jonathan Cooke on 23/09/2025.
//
// Unit tests for calculator.cpp

#include <boost/test/unit_test.hpp>

#include "calculator.h"
#include "test_fixtures.h"

// All unit tests for calculator.cpp
BOOST_AUTO_TEST_SUITE(calculator);

BOOST_FIXTURE_TEST_CASE(startup_test, CalculatorCleanStartupF)
{
  jcalc::mode mode;
  mode = this->operator->()->getMode();
  
  BOOST_TEST(mode == jcalc::NONE);
}

BOOST_AUTO_TEST_CASE(exit_test)
{
  int i = 1;
  jcalc::Calculator calculator;
  
  i = calculator.exit();
  
  BOOST_TEST(i == 0);
}


BOOST_FIXTURE_TEST_CASE(receive_input_test, CalculatorCleanStartupF)
{
  bool input_received;
  std::string input_string = "0";
  input_received = this->operator->()->input(input_string);
  
  BOOST_TEST(input_received);
}

BOOST_FIXTURE_TEST_CASE(accept_numbers_input_test, CalculatorCleanStartupF)
{
  bool input_accepted = true;
  std::string input_string = "0123456789";
  
  try {
    this->operator->()->input(input_string);
  } catch (std::invalid_argument) {
    input_accepted = false;
  };
  
  BOOST_TEST(input_accepted);
}

BOOST_FIXTURE_TEST_CASE(accept_spaces_input_test, CalculatorCleanStartupF)
{
  bool input_accepted = true;
  std::string input_string = " ";
  
  try {
    this->operator->()->input(input_string);
  } catch (std::invalid_argument) {
    input_accepted = false;
  };
  
  BOOST_TEST(input_accepted);
}

BOOST_FIXTURE_TEST_CASE(accept_operators_input_test, CalculatorCleanStartupF)
{
  bool input_accepted = true;
  std::string input_string = "+-";
  
  try {
    this->operator->()->input(input_string);
  } catch (std::invalid_argument) {
    input_accepted = false;
  };
  
  BOOST_TEST(input_accepted);
}

BOOST_FIXTURE_TEST_CASE(zero_test, CalculatorCleanStartupF)
{
  int currentValue = 1;
  currentValue = this->operator->()->getCurrentValue();
  
  BOOST_TEST(currentValue == 0);
}

BOOST_FIXTURE_TEST_CASE(addition_input_test, CalculatorCleanStartupF)
{
  std::string input_string_1 = "1";
  std::string input_string_2 = "+";
  std::string input_string_3 = "1";
  
  this->operator->()->input(input_string_1);
  this->operator->()->input(input_string_2);
  this->operator->()->input(input_string_3);
  
  int currentValue = this->operator->()->getCurrentValue();
  
  BOOST_TEST(currentValue == 2);
}

BOOST_FIXTURE_TEST_CASE(subtract_input_test, CalculatorCleanStartupF)
{
  std::string input_string_1 = "2";
  std::string input_string_2 = "-";
  std::string input_string_3 = "1";
  
  this->operator->()->input(input_string_1);
  this->operator->()->input(input_string_2);
  this->operator->()->input(input_string_3);
  
  int currentValue = this->operator->()->getCurrentValue();
  
  BOOST_TEST(currentValue == 1);
}

BOOST_FIXTURE_TEST_CASE(addition_string_test, CalculatorCleanStartupF)
{
  std::string input_string = "10 + 10";
  
  this->operator->()->input(input_string);
  
  int currentValue = this->operator->()->getCurrentValue();
  
  BOOST_TEST(currentValue == 20);
}

BOOST_FIXTURE_TEST_CASE(substract_string_test, CalculatorCleanStartupF)
{
  std::string input_string = "20 - 10";
  
  this->operator->()->input(input_string);
  
  int currentValue = this->operator->()->getCurrentValue();
  
  BOOST_TEST(currentValue == 10);
}

BOOST_AUTO_TEST_SUITE_END();
