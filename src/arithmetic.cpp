//
//  arithmetic.cpp
//  JCalc
//
//  Created by Jonathan Cooke on 26/09/2025.
//

#include "arithmetic.h"

namespace jcalc {

void Arithmetic::add(unsigned int &currentValue, unsigned int &currentInput) {
  currentValue = currentValue + currentInput;
  currentInput = 0;
}

void Arithmetic::subtract(unsigned int &currentValue,
                          unsigned int &currentInput) {
  currentValue = currentValue - currentInput;
  currentInput = 0;
}

void Arithmetic::multiply(unsigned int &currentValue,
                          unsigned int& currentInput) {
  currentValue = currentValue * currentInput;
  currentInput = 0;
}

void Arithmetic::divide(unsigned int &currentValue,
                        unsigned int& currentInput) {
  currentValue = currentValue / currentInput;
  currentInput = 0;
}

}
