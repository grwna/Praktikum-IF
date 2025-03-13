#include <iostream>
#include "BigNumber.hpp"
using namespace std;

int max_digit = 20;
ostream& operator<<(ostream& os, const BigNumber& bn) {
  bool foundNonZero = false;
  for (int i = max_digit - 1; i >= 0; i--) {
    if (bn[i] > 0) {
      foundNonZero = true;
    }
    if (foundNonZero) {
      os << bn[i];
    }
  }
  if (!foundNonZero) {
    os << "0";
  }
  return os;
}

int main() {
  BigNumber a(100), b(99);
  cout << a << endl; // 123
  cout << b << endl; // 2210
  cout << (a < b) << endl; // 1
  cout << (a > b) << endl; // 0
  cout << (a + b) << endl; // 2333
  return 0;
}