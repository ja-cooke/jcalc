//
//  test_fixtures.h
//  JCalcTest
//
//  Created by Jonathan Cooke on 26/09/2025.
//

#ifndef test_fixtures_h
#define test_fixtures_h

#include "calculator.h"

// -----------------------------------------------------------------------------
// --------------------------- test_calculator ---------------------------------
// -----------------------------------------------------------------------------

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

// Test fixture to construct and destroy an instance of the Calculator class
// with the default settings, and redirect cin to read a dummy input stream.
struct CalculatorDummyCinF {
  CalculatorDummyCinF() : calculator(std::make_unique<jcalc::Calculator>())
  {
    BOOST_TEST_MESSAGE( "setup fixture" );
    //defaultCin = std::cin.rdbuf(); // Store default buffer
  }
  
  ~CalculatorDummyCinF()
  {
    BOOST_TEST_MESSAGE( "teardown fixture" );
    calculator->exit();
    //std::cin.rdbuf(defaultCin); // Restore default buffer
  }

  jcalc::Calculator* operator->() { return calculator.get(); }
  jcalc::Calculator& operator*()  { return *calculator; }

public:
  // Helper to assist with cin buffer redirection.
  struct CinRedirectHelper {
    CinRedirectHelper(std::streambuf* redirectBuf) :
    defaultBuf(std::cin.rdbuf(redirectBuf)){}
    
    ~CinRedirectHelper() {
      std::cin.rdbuf(defaultBuf); // Buffer restore
    }
  private:
    std::streambuf* defaultBuf;
  };
  
private:
  std::unique_ptr<jcalc::Calculator> calculator;
  std::streambuf* defaultCin;
};

struct CalculatorDummyCoutF {
  CalculatorDummyCoutF() : calculator(std::make_unique<jcalc::Calculator>())
  {
    BOOST_TEST_MESSAGE( "setup fixture" );
  }
  
  ~CalculatorDummyCoutF()
  {
    BOOST_TEST_MESSAGE( "teardown fixture" );
    calculator->exit();
  }

  jcalc::Calculator* operator->() { return calculator.get(); }
  jcalc::Calculator& operator*()  { return *calculator; }
  
public:
  // Helper to assist with cout buffer redirection.
  struct CoutRedirectHelper {
    CoutRedirectHelper(std::ostream& redirectBuf) :
    defaultBuf(std::cout.rdbuf(redirectBuf.rdbuf())) {}
    
    ~CoutRedirectHelper() {
      std::cout.rdbuf(defaultBuf);
    }
  private:
    std::streambuf* defaultBuf;
  };
  
private:
  std::unique_ptr<jcalc::Calculator> calculator;
  std::streambuf* defaultCout;
};

// -----------------------------------------------------------------------------
// --------------------------- test_input_parser -------------------------------
// -----------------------------------------------------------------------------

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

// -----------------------------------------------------------------------------
// --------------------------- test_arithmetic ---------------------------------
// -----------------------------------------------------------------------------

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
