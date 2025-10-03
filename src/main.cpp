//
//  main.cpp
//  JCalc
//
//  Created by Jonathan Cooke on 21/09/2025.
//
// This file is the entry point for the application.
// To run the unit tests, the entry point is "test/test.cpp".

#include <iostream>

#include "calculator.h"

int main(int argc, const char * argv[]) {
  // Shows that the program is running in case the Calculator class fails to
  // initialise. All other code should be run using Calculator directly to
  // preserve model of test coverage.
  std::cout << "Starting JCalc...\n";
  
  jcalc::Calculator calculator;
  calculator.run();
  
  return 0;
}
