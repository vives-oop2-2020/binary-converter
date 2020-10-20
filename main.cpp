// Compile: g++ main.cpp binary_converter.cpp -o convert
// Run: ./convert

#include <iostream>
#include "binary_converter.h"

using namespace std;

std::string request_binary(void) {
  cout << "Please enter a binary value: ";
  std::string binary;
  getline(cin, binary);     // Read a full line (can contain spaces)
  return binary;
}

int main() {

  BinaryConverter converter;

  std::string binary = converter.cleanup_binary(request_binary());
  int decimal = converter.binary_to_decimal(binary);
  cout << "Binary \"" << binary << "\" is equal to " << decimal << " in decimal " << endl;

  decimal = 130;
  binary = converter.decimal_to_binary(decimal);
  cout << "Decimal " << decimal << " is equal to \"" << binary << "\" in binary " << endl;

  return 0;
}