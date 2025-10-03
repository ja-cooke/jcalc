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

// currentMode is None on startup
BOOST_FIXTURE_TEST_CASE(startup_test, CalculatorCleanStartupF)
{
  jcalc::mode mode;
  mode = this->operator->()->getMode();
  
  BOOST_TEST(mode == jcalc::None);
}

// exit() returns 0
BOOST_AUTO_TEST_CASE(exit_test)
{
  int i = 1;
  jcalc::Calculator calculator;
  
  i = calculator.exit();
  
  BOOST_TEST(i == 0);
}

// true returned when input() receives a string of "0"
BOOST_FIXTURE_TEST_CASE(receive_input_test, CalculatorCleanStartupF)
{
  bool inputReceived;
  std::string inputString = "0";
  inputReceived = this->operator->()->input(inputString);
  
  BOOST_TEST(inputReceived);
}

// true returned when input() receives "0123456789"
BOOST_FIXTURE_TEST_CASE(accept_numbers_input_test, CalculatorCleanStartupF)
{
  std::string inputString = "0123456789";
  
  try {
    this->operator->()->input(inputString);
  } catch (std::invalid_argument) {
    BOOST_ERROR("input(\"0123456789\") raised an Invalid Argument exception.");
  };
}

// true returned when input() receives " "
BOOST_FIXTURE_TEST_CASE(accept_spaces_input_test, CalculatorCleanStartupF)
{
  std::string inputString = " ";
  
  try {
    this->operator->()->input(inputString);
  } catch (std::invalid_argument) {
    BOOST_ERROR("input(\" \") raised an Invalid Argument exception.");
  };
}

// true returned when input() receives supported operator character strings
// TODO: Move this test to test_input_parser.cpp
BOOST_FIXTURE_TEST_CASE(accept_operators_input_test, CalculatorCleanStartupF)
{
  std::vector<std::string> supportedOperators = {"+", "-", "*", "/"};
  
  for (std::string s : supportedOperators) {
    try {
      this->operator->()->input(s);
    }
    catch (std::invalid_argument) {
      BOOST_ERROR("Input '" << s << "' threw Invalid Argument.");
    }
  }
  
  std::string multipleOperatorString("+-*/");
  BOOST_CHECK_NO_THROW(this->operator->()->input(multipleOperatorString));
}

// currentValue is initialised to 0 on construction of Calculator
BOOST_FIXTURE_TEST_CASE(zero_test, CalculatorCleanStartupF)
{
  int currentValue = 1;
  currentValue = this->operator->()->getCurrentValue();
  
  BOOST_TEST(currentValue == 0);
}

// Sequence of "1", "+", "1" to input gives a current value of "2"
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

// Sequence of "2", "-", "1" to input gives a current value of "2"
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

// String input of "10 + 10" gives a current value of "20"
BOOST_FIXTURE_TEST_CASE(addition_string_test, CalculatorCleanStartupF)
{
  std::string inputString = "10 + 10";
  
  this->operator->()->input(inputString);
  
  int currentValue = this->operator->()->getCurrentValue();
  
  BOOST_TEST(currentValue == 20);
}

// String input of "20 - 10" gives a current value of "10"
BOOST_FIXTURE_TEST_CASE(addition_string_no_spaces_test, CalculatorCleanStartupF)
{
  std::string inputString = "10+10";
  
  this->operator->()->input(inputString);
  
  int currentValue = this->operator->()->getCurrentValue();
  
  BOOST_TEST(currentValue == 20);
}

// String input of "10+10" gives a current value of "20"
BOOST_FIXTURE_TEST_CASE(substract_string_test, CalculatorCleanStartupF)
{
  std::string inputString = "20 - 10";
  
  this->operator->()->input(inputString);
  
  int currentValue = this->operator->()->getCurrentValue();
  
  BOOST_TEST(currentValue == 10);
}

// String input of "20-10" gives a current value of "10"
BOOST_FIXTURE_TEST_CASE(substract_string_no_spaces_test, CalculatorCleanStartupF)
{
  std::string inputString = "20-10";
  
  this->operator->()->input(inputString);
  
  int currentValue = this->operator->()->getCurrentValue();
  
  BOOST_TEST(currentValue == 10);
}

// read(); for a simulated std::cin of "10+10" gives a current value of "20"
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

// read(); for a simulated std::cin of "1+2+3+4+5" gives a current value of "15"
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

// Print result to console "0" on startup
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

BOOST_FIXTURE_TEST_CASE(run_test, CalculatorDummyCinF)
{
  std::istringstream dummyStream("exit\n");
  {
    CinRedirectHelper guard(dummyStream.rdbuf());
    BOOST_CHECK_NO_THROW(this->operator->()->run());
  }
}

BOOST_AUTO_TEST_SUITE_END();
