//
//  test.cpp
//  JCalcTest
//
//  Created by Jonathan Cooke on 21/09/2025.
//

#define BOOST_TEST_MODULE My Test
#include <boost/test/included/unit_test.hpp>
#include "calculator.h"

BOOST_AUTO_TEST_CASE(first_test)
{
  int i = 1;
  Calculator calculator;
  i = calculator.start();
  
  BOOST_TEST(i == 0);
}

BOOST_AUTO_TEST_CASE(second_test)
{
  int i = 1;
  Calculator calculator;
  i = calculator.exit();
  
  BOOST_TEST(i == 0);
}
