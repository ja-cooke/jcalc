//
//  calculator.cpp
//  JCalc
//
//  Created by Jonathan Cooke on 21/09/2025.
//
// All calculator program functions should be runnable using the Calculator
// class and jcalc namespace alone.

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "calculator.h"

//
namespace jcalc {

Calculator::Calculator(){
  // Always set the mode to NONE on startup
  currentMode = NONE;
  currentValue = 0;
}

// Terminates the program
int Calculator::exit(){
  return 0;
}

// Receives and verifies input strings as valid or invalid
bool Calculator::input(std::string& input_string){
  
  try {
    inputParser.stringValid(input_string, maxCharacterLength);
  } catch (std::invalid_argument) {
    throw std::invalid_argument("Input string invalid");
  }
  
  if (inputParser.charactersInvalid(input_string)) {
    return false;
  }
  else{
    update(input_string);
    return true;
  }
}

// Uses the current mode and input to call a calculation function.
void Calculator::calculate() {
  switch (currentMode) {
    case ADD:
      arithmetic.add(currentValue, inputValue);
      break;
    case SUBTRACT:
      arithmetic.subtract(currentValue, inputValue);
      break;
    case NONE:
      currentValue = inputValue;
      inputValue = 0;
      break;
      
    default:
      break;
  }
}

void Calculator::read(){
  std::string input_string;
  std::cin >> input_string;
  input(input_string);
}

// Change the state of the calculator depending on the input type
void Calculator::update(std::string& input_string) {
  
  // First split the string into individual operations
  std::vector<std::string> input_substrings;
  inputParser.splitInputString(input_string, input_substrings);
  
  // Execute the individual operations in turn
  for (std::string s : input_substrings) {
    char c = s[0];
    
    // Assume string is a single unsigned integer, store as the inputValue.
    if (std::isdigit(c)) {
      inputValue = std::stoi(s);
      calculate();
    }
    else {
      // Maths operators to change mode
      switch (c) {
        case '+':
          currentMode = ADD;
          break;
        case '-':
          currentMode = SUBTRACT;
          break;
          
        default:
          break;
      }
    }
  }
}

// Getters
int Calculator::getCurrentValue(){
  return currentValue;
}

mode Calculator::getMode(){
  return currentMode;
}

}

