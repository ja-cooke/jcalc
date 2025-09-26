//
//  calculator.cpp
//  JCalc
//
//  Created by Jonathan Cooke on 21/09/2025.
//
// All calculator program functions should be runnable using the Calculator
// class and jcalc namespace alone.

#include <stdio.h>
#include <stdexcept>

#include "calculator.h"

//
namespace jcalc {

Calculator::Calculator(){
  // Always set the mode to NONE on startup
  currentMode = NONE;
  currentValue = 0;
}

void Calculator::add(int &currentValue, int &currentInput) {
  currentValue = currentValue + currentInput;
}

void Calculator::subtract(int &currentValue, int &currentInput) {
  currentValue = currentValue - currentInput;
}


// Terminates the program
int Calculator::exit(){
  return 0;
}

// Receives and verifies input strings as valid or invalid
int Calculator::input(std::string& input_string){
  if (input_string.empty()) {
    throw std::invalid_argument("Empty input received");
  }
  if (input_string.length() > maxCharacterLength) {
    throw std::invalid_argument("Input too long");
  }
  
  // Allowed characters are arabic numerals 0-9, '+', '-' and ' '.
  bool invalidCharacters = false;
  for (char c : input_string) {
    if (std::isdigit(c) || c == '+' || c == '-' || c == ' ') {
      continue;
    }
    else {
      invalidCharacters = true;
      throw std::invalid_argument("Invalid input character");
    }
  }
 
  if (invalidCharacters) {
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
      add(currentValue, inputValue);
      break;
    case SUBTRACT:
      subtract(currentValue, inputValue);
    case NONE:
      currentValue = inputValue;
      inputValue = 0;
      break;
      
    default:
      break;
  }
}

void Calculator::update(std::string& input_string) {
  char c = input_string[0];
  
  // Change the state of the calculator depending on the input type
  
  // Assume string is a single unsigned integer, store as the inputValue.
  if (std::isdigit(c)) {
    inputValue = std::stoi(input_string);
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
  calculate();
}

// Getters
int Calculator::getCurrentValue(){
  return currentValue;
}

mode Calculator::getMode(){
  return currentMode;
}

}

