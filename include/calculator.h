//
//  calculator.h
//  JCalc
//
//  Created by Jonathan Cooke on 21/09/2025.
//
// Provides access to all public access functions and utilities of JCalc.
// To implement JCalc, only this header needs to be included in main().

#ifndef calculator_h
#define calculator_h

#include <string>

namespace jcalc {

// Calculator modes representing possible mathematical operations
enum mode {
  ADD,
  SUBTRACT,
  MULTIPLY,
  DIVIDE,
  NONE // For use on startup before the user choses a mode.
};

// Simple calculator which can accept mathematical arguments from user console
// input and return the results to the console.
class Calculator {
  
public:
  Calculator();
  int exit();
  int input(std::string& input_string);
  
  // Getters & Setters
  mode getMode();
  
private:
  int currentValue;
  enum mode currentMode;
  int maxCharacterLength = 19;
};

}

#endif /* calculator_h */
