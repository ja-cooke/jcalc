//
//  arithmetic.h
//  JCalc
//
//  Created by Jonathan Cooke on 26/09/2025.
//

#ifndef arithmetic_h
#define arithmetic_h

namespace jcalc {

class Arithmetic {
public:
  void add(unsigned int& currentValue, unsigned int& inputValue);
  void subtract(unsigned int& currentValue, unsigned int& inputValue);
  void multiply(unsigned int& currentValue, unsigned int& inputValue);
  void divide(unsigned int& currentValue, unsigned int& inputValue);
};

}

#endif /* arithmetic_h */
