#include <iostream>
#include <cstdlib>
#include "arrays.hpp"

using namespace std;

int main()
{
  int n;
  cin >> n;
  int array[n];
  for (int i=0; i < n; i++)
  {
    array[i] = rand() % 200 - 100;
    cout << array[i] << ' ';
  }
  cout << endl;

  cout << "Maximal even number: " << maxeven(array, n) << endl;
  cout << "Minimal odd number: " << minodd(array, n) << endl;
  cout << "Amount of positive numbers: " << posnumber(array, n) << endl;
  cout << "Product of first 5 numbers: " << fproduct(array, n) << endl;
  cout << "Sum of all negative numbers: " << negsum(array, n) << endl;
  
  return 0;
}
