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
}

// Terminates the program
int Calculator::exit(){
  return 0;
};

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
    return true;
  }
}

// Getters
mode Calculator::getMode(){
  return currentMode;
};

}

