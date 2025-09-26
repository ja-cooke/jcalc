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

BOOST_FIXTURE_TEST_CASE(addition_test, ArithmeticF)
{
  unsigned int test_int_1 = 1;
  unsigned int test_int_2 = 1;
  this->operator*().add(test_int_1, test_int_2);
  
  BOOST_TEST(test_int_1 == 2);
  BOOST_TEST(test_int_2 == 0);
}

BOOST_FIXTURE_TEST_CASE(subtraction_test, ArithmeticF)
{
  unsigned int test_int_1 = 2;
  unsigned int test_int_2 = 1;
  this->operator*().subtract(test_int_1, test_int_2);
  
  BOOST_TEST(test_int_1 == 1);
  BOOST_TEST(test_int_2 == 0);
}

BOOST_FIXTURE_TEST_CASE(multiplication_test, ArithmeticF)
{
  unsigned int test_int_1 = 20;
  unsigned int test_int_2 = 10;
  this->operator*().multiply(test_int_1, test_int_2);
  
  BOOST_TEST(test_int_1 == 200);
  BOOST_TEST(test_int_2 == 0);
}

BOOST_FIXTURE_TEST_CASE(division_test, ArithmeticF)
{
  unsigned int test_int_1 = 200;
  unsigned int test_int_2 = 10;
  this->operator*().divide(test_int_1, test_int_2);
  
  BOOST_TEST(test_int_1 == 20);
  BOOST_TEST(test_int_2 == 0);
}

BOOST_AUTO_TEST_SUITE_END();
