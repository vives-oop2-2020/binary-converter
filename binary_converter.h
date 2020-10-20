#pragma once

#include <string>

class BinaryConverter {

  public:
    int binary_to_decimal(std::string binary);
    
    std::string decimal_to_binary(unsigned int decimal);

  private:
    std::string remove_spaces(std::string value);
};