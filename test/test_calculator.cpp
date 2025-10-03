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
  
  BOOST_TEST(mode == jcalc::None);
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
  bool inputReceived;
  std::string inputString = "0";
  inputReceived = this->operator->()->input(inputString);
  
  BOOST_TEST(inputReceived);
}

BOOST_FIXTURE_TEST_CASE(accept_numbers_input_test, CalculatorCleanStartupF)
{
  bool inputAccepted = true;
  std::string inputString = "0123456789";
  
  try {
    this->operator->()->input(inputString);
  } catch (std::invalid_argument) {
    inputAccepted = false;
  };
  
  BOOST_TEST(inputAccepted);
}

BOOST_FIXTURE_TEST_CASE(accept_spaces_input_test, CalculatorCleanStartupF)
{
  bool inputAccepted = true;
  std::string inputString = " ";
  
  try {
    this->operator->()->input(inputString);
  } catch (std::invalid_argument) {
    inputAccepted = false;
  };
  
  BOOST_TEST(inputAccepted);
}

BOOST_FIXTURE_TEST_CASE(accept_operators_input_test, CalculatorCleanStartupF)
{
  bool inputAccepted = true;
  std::string inputString = "+-";
  
  try {
    this->operator->()->input(inputString);
  } catch (std::invalid_argument) {
    inputAccepted = false;
  };
  
  BOOST_TEST(inputAccepted);
}

BOOST_FIXTURE_TEST_CASE(zero_test, CalculatorCleanStartupF)
{
  int currentValue = 1;
  currentValue = this->operator->()->getCurrentValue();
  
  BOOST_TEST(currentValue == 0);
}

BOOST_FIXTURE_TEST_CASE(addition_input_test, CalculatorCleanStartupF)
{
  std::string inputString1 = "1";
  std::string inputString2 = "+";
  std::string inputString3 = "1";
  
  this->operator->()->input(inputString1);
  this->operator->()->input(inputString2);
  this->operator->()->input(inputString3);
  
  int currentValue = this->operator->()->getCurrentValue();
  
  BOOST_TEST(currentValue == 2);
}

BOOST_FIXTURE_TEST_CASE(subtract_input_test, CalculatorCleanStartupF)
{
  std::string inputString1 = "2";
  std::string inputString2 = "-";
  std::string inputString3 = "1";
  
  this->operator->()->input(inputString1);
  this->operator->()->input(inputString2);
  this->operator->()->input(inputString3);
  
  int currentValue = this->operator->()->getCurrentValue();
  
  BOOST_TEST(currentValue == 1);
}

BOOST_FIXTURE_TEST_CASE(addition_string_test, CalculatorCleanStartupF)
{
  std::string inputString = "10 + 10";
  
  this->operator->()->input(inputString);
  
  int currentValue = this->operator->()->getCurrentValue();
  
  BOOST_TEST(currentValue == 20);
}

BOOST_FIXTURE_TEST_CASE(addition_string_no_spaces_test, CalculatorCleanStartupF)
{
  std::string inputString = "10+10";
  
  this->operator->()->input(inputString);
  
  int currentValue = this->operator->()->getCurrentValue();
  
  BOOST_TEST(currentValue == 20);
}

BOOST_FIXTURE_TEST_CASE(substract_string_test, CalculatorCleanStartupF)
{
  std::string inputString = "20 - 10";
  
  this->operator->()->input(inputString);
  
  int currentValue = this->operator->()->getCurrentValue();
  
  BOOST_TEST(currentValue == 10);
}

BOOST_FIXTURE_TEST_CASE(substract_string_no_spaces_test, CalculatorCleanStartupF)
{
  std::string inputString = "20-10";
  
  this->operator->()->input(inputString);
  
  int currentValue = this->operator->()->getCurrentValue();
  
  BOOST_TEST(currentValue == 10);
}

BOOST_FIXTURE_TEST_CASE(user_input_test, CalculatorDummyCinF)
{
  int currentValue = 0;
  
  std::istringstream dummyStream("10+10\n");
  {
    CinRedirectHelper guard(dummyStream.rdbuf());
    this->operator->()->read();
  }
  
  currentValue = this->operator->()->getCurrentValue();
  BOOST_TEST(currentValue == 20);
}

BOOST_FIXTURE_TEST_CASE(user_input_long_test, CalculatorDummyCinF)
{
  int currentValue = 0;
  
  std::istringstream dummyStream("1+2+3+4+5\n");
  {
    CinRedirectHelper guard(dummyStream.rdbuf());
    this->operator->()->read();
  }
  
  currentValue = this->operator->()->getCurrentValue();
  BOOST_TEST(currentValue == 15);
}

BOOST_FIXTURE_TEST_CASE(print_test, CalculatorDummyCoutF)
{
  std::ostringstream dummyStream;
  {
    CoutRedirectHelper guard(dummyStream);
    this->operator->()->print();
  }
  std::string outputString = dummyStream.str();
  
  BOOST_TEST(outputString == "0\n");
}

BOOST_AUTO_TEST_SUITE_END();
