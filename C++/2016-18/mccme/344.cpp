#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {

  string binary;
  cin >> binary;
  int decimal = 0;

  for (size_t i = 0; i < binary.size(); i++) {
    int digit = binary[i] - '0';
    decimal += digit * pow(2, binary.size()-1-i);
  }

  cout << decimal << endl;

  return 0;
}
