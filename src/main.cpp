//
//  main.cpp
//  JCalc
//
//  Created by Jonathan Cooke on 21/09/2025.
//

#include <iostream>
#include "calculator.h"

int main(int argc, const char * argv[]) {
  // Check compilation
  std::cout << "Starting JCalc...\n";
  
  jcalc::Calculator calculator;
  
  calculator.start();
  calculator.exit();
  
  return 0;
}
