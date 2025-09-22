//
//  calculator.h
//  JCalc
//
//  Created by Jonathan Cooke on 21/09/2025.
//

#ifndef calculator_h
#define calculator_h

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
  
  // Getters
  mode getMode();
};

}

#endif /* calculator_h */
