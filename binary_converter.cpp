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
  std::string binary = "";
  while (decimal > 1) {
    int digit = decimal % 2;
    binary = std::to_string(digit) + binary;
    decimal = decimal / 2;
  }
  binary = std::to_string(decimal) + binary;

  return cleanup_binary(binary);
}

// Makes is all nice and tighty binary
std::string BinaryConverter::cleanup_binary(std::string binary) {
  binary = remove_invalid_characters(binary);
  binary = add_padding(binary);
  binary = separate(binary);
  return binary;
}

// Group by number of digits
std::string BinaryConverter::separate(std::string original, int group, char separator) {
  original = remove_spaces(original);

  std::string binary = "";
  int digits = 0;
  for (int i = original.length()-1; i >= 0; i--) {
    binary = original[i] + binary;    // Add bit before previous cleaned
    digits++;
    if (digits % group == 0 && i > 0) {
      binary = " " + binary;
    }
  }

  return binary;
}

// Add padding if needed at the left (expects valid binary).
// Removes all spaces as it does not know grouping rules
std::string BinaryConverter::add_padding(std::string binary, int totalDigits) {
  binary = remove_spaces(binary);

  for (int i = binary.length(); i < totalDigits; i++) {
    binary = '0' + binary;
  }

  return binary;
}

// Remove all invalid characters. Leaves only 0, 1 and space character
std::string BinaryConverter::remove_invalid_characters(std::string value) {
  std::string cleaned = "";
  for (int i = 0; i < value.length(); i++) {
    if (value[i] == '0' || value[i] == '1' || value[i] == ' ') {
      cleaned += value[i];
    }
  }
  return cleaned;
}

// Remove all spaces (expects valid binary for all chars)
std::string BinaryConverter::remove_spaces(std::string value) {
  int position = value.find(" ");
  while (position >= 0) {
    value = value.erase(position, 1);
    position = value.find(" ");
  }

  return value;
}