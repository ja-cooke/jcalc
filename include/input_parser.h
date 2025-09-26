//
//  input_parser.h
//  JCalc
//
//  Created by Jonathan Cooke on 26/09/2025.
//

#ifndef input_parser_h
#define input_parser_h

#include <string>

namespace jcalc {

class InputParser {
public:
  void stringValid(std::string& input_string, int maxCharacterLength);
  bool charactersInvalid(std::string& input_string);
};

}

#endif /* input_parser_h */
