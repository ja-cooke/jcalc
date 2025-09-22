//
//  test.cpp
//  JCalcTest
//
//  Created by Jonathan Cooke on 21/09/2025.
//

#define BOOST_TEST_MODULE My Test
#include <boost/test/included/unit_test.hpp>
#include "calculator.h"

BOOST_AUTO_TEST_CASE(start_test)
{
  int i = 1;
  jcalc::Calculator calculator;
  i = calculator.start();
  
  BOOST_TEST(i == 0);
}

BOOST_AUTO_TEST_CASE(exit_test)
{
  int i = 1;
  jcalc::Calculator calculator;
  i = calculator.exit();
  
  BOOST_TEST(i == 0);
}

BOOST_AUTO_TEST_CASE(startup_mode_test)
{
  
  jcalc::mode mode;
  jcalc::Calculator calculator;
  
  calculator.start();
  mode = calculator.getMode();
  
  BOOST_TEST(mode == jcalc::NONE);
}
