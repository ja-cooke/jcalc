//
//  input_parser.h
//  JCalc
//
//  Created by Jonathan Cooke on 26/09/2025.
//

#ifndef input_parser_h
#define input_parser_h

#include <string>
#include <vector>

namespace jcalc {

class InputParser {
public:
  void stringValid(std::string& inputString, int maxCharacterLength);
  void charactersInvalid(std::string& inputString);
  void splitInputString(std::string& inputString,
                        std::vector<std::string>& outputSubstrings);
};

}

#endif /* input_parser_h */
