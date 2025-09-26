//
//  input_parser.cpp
//  JCalc
//
//  Created by Jonathan Cooke on 26/09/2025.
//

#include <stdio.h>

#include "input_parser.h"

namespace jcalc {

void InputParser::stringValid(std::string& input_string,
                              int maxCharacterLength) {
  if (input_string.empty()) {
    throw std::invalid_argument("Empty input received");
  }
  if (input_string.length() > maxCharacterLength) {
    throw std::invalid_argument("Input too long");
  }
}

bool InputParser::charactersInvalid(std::string& input_string){
  
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
  return invalidCharacters;
}

}
