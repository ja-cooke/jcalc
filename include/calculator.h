//
//  calculator.h
//  JCalc
//
//  Created by Jonathan Cooke on 21/09/2025.
//

#ifndef calculator_h
#define calculator_h

#include <string>

namespace jcalc {

enum mode {
  ADD,
  SUBTRACT,
  MULTIPLY,
  DIVIDE,
  NONE
};

class Calculator {
  
  int currentValue;
  enum mode currentMode;
  
public:
  int start();
  int exit();
  int input(std::string& input_string);
  
  // Getters & Setters
  mode getMode();
  
private:
  int maxCharacterLength = 19;
};

}

#endif /* calculator_h */
