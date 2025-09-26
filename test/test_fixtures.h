//
//  test_fixtures.h
//  JCalcTest
//
//  Created by Jonathan Cooke on 26/09/2025.
//

#ifndef test_fixtures_h
#define test_fixtures_h

#include "calculator.h"

// Test fixture to construct and destroy an instance of the Calculator class
// with the default startup settings.
struct CalculatorCleanStartupF {
  CalculatorCleanStartupF() : calculator(std::make_unique<jcalc::Calculator>())
  {
    BOOST_TEST_MESSAGE( "setup fixture" );
  }
  
  ~CalculatorCleanStartupF()
  {
    BOOST_TEST_MESSAGE( "teardown fixture" );
    calculator->exit();
  }

  jcalc::Calculator* operator->() { return calculator.get(); }
  jcalc::Calculator& operator*()  { return *calculator; }

private:
  std::unique_ptr<jcalc::Calculator> calculator;
};

struct InputParserF {
  InputParserF() : inputParser(std::make_unique<jcalc::InputParser>())
  {
    BOOST_TEST_MESSAGE( "setup fixture" );
  }
  
  ~InputParserF()
  {
    BOOST_TEST_MESSAGE( "teardown fixture" );
  }

  jcalc::InputParser* operator->() { return inputParser.get(); }
  jcalc::InputParser& operator*()  { return *inputParser; }

private:
  std::unique_ptr<jcalc::InputParser> inputParser;
public:
  int maxCharacterLength = 19;
};

struct ArithmeticF {
  ArithmeticF() : arithmetic(std::make_unique<jcalc::Arithmetic>())
  {
    BOOST_TEST_MESSAGE( "setup fixture" );
  }
  
  ~ArithmeticF()
  {
    BOOST_TEST_MESSAGE( "teardown fixture" );
  }

  jcalc::Arithmetic* operator->() { return arithmetic.get(); }
  jcalc::Arithmetic& operator*()  { return *arithmetic; }

private:
  std::unique_ptr<jcalc::Arithmetic> arithmetic;
};


#endif /* test_fixtures_h */
