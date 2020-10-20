#include "binary_converter.h"

int BinaryConverter::binary_to_decimal(std::string binary) {
  // Remove all spaces
  binary = remove_spaces(binary);

  int decimal = 0;
  for (unsigned int i = 0; i < binary.length(); i++) {
    int digit = binary[i] - '0';
    decimal += (digit << (binary.length() - 1 - i));
  }

  return decimal;
}

std::string BinaryConverter::decimal_to_binary(unsigned int decimal) {
  // if (decimal == 0) {
  //   return "0";
  // }

  std::string binary = "";
  while (decimal > 1) {
    int digit = decimal % 2;
    binary = std::to_string(digit) + binary;
    decimal = decimal / 2;
  }
  binary = std::to_string(decimal) + binary;

  return binary;
}

std::string BinaryConverter::remove_spaces(std::string value) {
  int position = value.find(" ");
  while (position >= 0) {
    value = value.erase(position, 1);
    position = value.find(" ");
  }

  return value;
}