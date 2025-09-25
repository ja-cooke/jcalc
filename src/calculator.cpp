//
//  calculator.cpp
//  JCalc
//
//  Created by Jonathan Cooke on 21/09/2025.
//

#include <stdio.h>
#include <stdexcept>

#include "calculator.h"

namespace jcalc {

int Calculator::start(){
  // Always set the mode to NONE on startup
  currentMode = NONE;
  
  return 0;
};

int Calculator::exit(){
  return 0;
};

int Calculator::input(std::string& input_string){
  if (input_string.empty()) {
    throw std::invalid_argument("Empty input received");
  }
  if (input_string.length() > maxCharacterLength) {
    throw std::invalid_argument("Input too long");
  }
  
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
  
  return false;
}

// Getters
mode Calculator::getMode(){
  return currentMode;
};

}

