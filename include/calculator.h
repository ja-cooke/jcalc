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
  void print(std::string& output_string);
  
  // Getters & Setters
  mode getMode();
  int getCurrentValue();
  
private:
  int currentValue = 0;
  int inputValue = 0;
  enum mode currentMode = NONE;
  int maxCharacterLength = 19;
  
  void update(std::string& input_string);
  void add(int& currentValue, int& inputValue);
  void subtract(int& currentValue, int& inputValue);
  void multiply(int& currentValue, int& inputValue);
  void divide(int& currentValue, int& inputValue);
  void clear();
  void calculate();
};

}

#endif /* calculator_h */
