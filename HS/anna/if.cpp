#include <iostream>
using namespace std;

int main()  {
  int a = 1;
  int b = 0;

  if (a == b)
  {
    cout << "right";
  }
  else if (a > b)
  {
    cout << "a is bigger b";
  }
  else if (a < b)
  {
    cout << "a is less b";
  }
  else
  {
    cout << "wrong";
  }
  return 0;
}
