//
//  input_parser.cpp
//  JCalc
//
//  Created by Jonathan Cooke on 26/09/2025.
//

#include <stdio.h>
#include <sstream>

#include "input_parser.h"

namespace jcalc {

void InputParser::stringValid(std::string& inputString,
                              int maxCharacterLength) {
  if (inputString.empty()) {
    throw std::invalid_argument("Empty input received");
  }
  if (inputString.length() > maxCharacterLength) {
    throw std::invalid_argument("Input too long");
  }
}

bool InputParser::charactersInvalid(std::string& inputString){
  
  // Allowed characters are arabic numerals 0-9, '+', '-' and ' '.
  bool invalidCharacters = false;
  for (char c : inputString) {
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

// Splits a string of digits, and non-digit character types sequentially into a
// vector of substrings of one type only. Also delimits using spaces.
// E.g. "qwert1234 5678yuio asdf" -> {"qwert","1234","5678","yuio","asdf"}
void InputParser::splitInputString(std::string& inputString,
                      std::vector<std::string>& outputSubstrings) {
  
  std::stringstream stringstream(inputString);
  std::string substring;
  char delimiter = ' ';
  
  // Splits strings into substrings wherever a space character occurs
  // Then splits further wherever the sting changes between digits and
  // operators.
  while (std::getline(stringstream, substring, delimiter)) {
    // Force the first character to be a breakpoint.
    // I.e. if substring[0] is a digit, assume the previous character was not
    // and visa versa.
    bool prevIsDigit = std::isdigit(substring[0]);
    // Variables to track substring indices
    int index = 0;
    int element_start = 0;
    int element_stop = 0;
    
    for (char c : substring) {
      // If the current character is not the same type as the previous (i.e.
      // numeral or maths operator) split the string there and add to the
      // vector of substrings.
      if (std::isdigit(c) != prevIsDigit) {
       
        element_stop = index;
        int length = element_stop - element_start;
        
        std::string string_element = substring.substr(element_start, length);
        outputSubstrings.push_back(string_element);
        
        // Starting index of the next element:
        element_start = index;
      }
      // If c is the final character in substring, push the remainder of the
      // substring to the output_strings vector.
      if (index == substring.length()-1) {
        element_stop = ++index; // == substring.length(): the end of the string
        int length = element_stop - element_start;
        std::string string_element = substring.substr(element_start, length);
        outputSubstrings.push_back(string_element);
        break; // Process complete: no need to set up for the next loop.
      }
      index++;
      prevIsDigit = std::isdigit(c);
    }
  }
}

}
