//
//  test_arithmetic.cpp
//  JCalcTest
//
//  Created by Jonathan Cooke on 26/09/2025.
//

#include <stdio.h>

#include <boost/test/unit_test.hpp>

#include "arithmetic.h"
#include "test_fixtures.h"

// All unit tests for arithmetic.cpp
BOOST_AUTO_TEST_SUITE(arithmetic);

// 1+1 returns 2, input cleared to 0
BOOST_FIXTURE_TEST_CASE(addition_test, ArithmeticF)
{
  unsigned int testInt1 = 1;
  unsigned int testInt2 = 1;
  this->operator*().add(testInt1, testInt2);
  
  BOOST_TEST(testInt1 == 2);
  BOOST_TEST(testInt2 == 0);
}

// 2-1 returns 1, input cleared to 0
BOOST_FIXTURE_TEST_CASE(subtraction_test, ArithmeticF)
{
  unsigned int testInt1 = 2;
  unsigned int testInt2 = 1;
  this->operator*().subtract(testInt1, testInt2);
  
  BOOST_TEST(testInt1 == 1);
  BOOST_TEST(testInt2 == 0);
}

// 20*10 returns 200, input cleared to 0
BOOST_FIXTURE_TEST_CASE(multiplication_test, ArithmeticF)
{
  unsigned int testInt1 = 20;
  unsigned int testInt2 = 10;
  this->operator*().multiply(testInt1, testInt2);
  
  BOOST_TEST(testInt1 == 200);
  BOOST_TEST(testInt2 == 0);
}

// 200/10 returns 20, input cleared to 0
BOOST_FIXTURE_TEST_CASE(division_test, ArithmeticF)
{
  unsigned int testInt1 = 200;
  unsigned int testInt2 = 10;
  this->operator*().divide(testInt1, testInt2);
  
  BOOST_TEST(testInt1 == 20);
  BOOST_TEST(testInt2 == 0);
}

BOOST_AUTO_TEST_SUITE_END();
