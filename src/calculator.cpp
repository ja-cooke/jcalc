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
  currentMode = None;
  currentValue = 0;
}

// Terminates the program
int Calculator::exit(){
  return 0;
}

// Receives and verifies input strings as valid or invalid
bool Calculator::input(std::string& inputString){
  
  try {
    inputParser.stringValid(inputString, maxCharacterLength);
  } catch (std::invalid_argument) {
    throw std::invalid_argument("Input string invalid");
  }
  
  if (inputParser.charactersInvalid(inputString)) {
    return false;
  }
  else{
    update(inputString);
    return true;
  }
}

// Uses the current mode and input to call a calculation function.
void Calculator::calculate() {
  switch (currentMode) {
    case Add:
      arithmetic.add(currentValue, inputValue);
      break;
    case Subtract:
      arithmetic.subtract(currentValue, inputValue);
      break;
    case None:
      currentValue = inputValue;
      inputValue = 0;
      break;
      
    default:
      break;
  }
}

void Calculator::print(){
  std::cout << currentValue << std::endl;
}

void Calculator::read(){
  std::string inputString;
  std::cin >> inputString;
  input(inputString);
}

// Change the state of the calculator depending on the input type
void Calculator::update(std::string& inputString) {
  
  // First split the string into individual operations
  std::vector<std::string> inputSubstrings;
  inputParser.splitInputString(inputString, inputSubstrings);
  
  // Execute the individual operations in turn
  for (std::string s : inputSubstrings) {
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
          currentMode = Add;
          break;
        case '-':
          currentMode = Subtract;
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

