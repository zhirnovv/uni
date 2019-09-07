#include <iostream>

using namespace std;

int main() {
  int input = 0; //переменная, идущая на вход
  cin >> input;  //ввод переменной

  int sideSum = input / 2; //т.к нам нужны только две стороны, делим на 2
  int side1 = sideSum / 2;
  int side2 = sideSum - side1;
  cout << side1 * side2 << endl;
  return 0;
}
