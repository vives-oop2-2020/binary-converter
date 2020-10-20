// Compile: g++ main.cpp binary_converter.cpp -o convert
// Run: ./convert

#include <iostream>
#include "binary_converter.h"

using namespace std;

int main() {

  BinaryConverter converter;

  int decimal = converter.binary_to_decimal("0000 0001");

  cout << "The result is " << decimal << endl;

  cout << '0' << ": " << (int)'0' << endl;
  cout << '1' << ": " << (int)'1' << endl;
  cout << ('1' - '0') << endl;

  std::string binary = converter.decimal_to_binary(130);
  cout << binary << endl;

  return 0;
}