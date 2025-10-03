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

#include "input_parser.h"
#include "arithmetic.h"

namespace jcalc {

// Calculator modes representing possible mathematical operations
enum mode {
  Add,
  Subtract,
  Multiply,
  Divide,
  None // For use on startup before the user choses a mode.
};

// Simple calculator which can accept mathematical arguments from user console
// input and return the results to the console.
class Calculator {
  
public:
  Calculator();
  void run();
  int exit();
  bool input(std::string& input_string);
  void print();
  void read();
  
  // Getters & Setters
  mode getMode();
  int getCurrentValue();
  
private:
  unsigned int currentValue = 0;
  unsigned int inputValue = 0;
  enum mode currentMode = None;
  int maxCharacterLength = 19;
  bool exitCalled = false;
  
  jcalc::InputParser inputParser;
  jcalc::Arithmetic arithmetic;
  
  void update(std::string& input_string);
  void clear();
  void calculate();
};

}

#endif /* calculator_h */
