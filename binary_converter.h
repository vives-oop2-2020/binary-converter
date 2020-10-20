#pragma once

#include <string>

class BinaryConverter {

  public:
    int binary_to_decimal(std::string binary);
    std::string decimal_to_binary(unsigned int decimal);

  public:
    std::string cleanup_binary(std::string binary);

  private:
    std::string separate(std::string original, int group = 8, char separator = ' ');
    std::string add_padding(std::string binary, int totalDigits = 32);
    std::string remove_invalid_characters(std::string value);
    std::string remove_spaces(std::string value);
};