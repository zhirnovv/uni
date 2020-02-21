#include "arrays3.hpp"

using namespace std;

int main()
{
  int n;
  cin >> n;

  int array[n];

  onetwo(array, n);
  onetwothree(array, n);
  twoplustwo(array, n);
  zerotwo(array, n);
  xfivesix(array, n);
  minusten(array, n);
  threeplusthree(array, n);
  random(array, n);

  return 0;
}
