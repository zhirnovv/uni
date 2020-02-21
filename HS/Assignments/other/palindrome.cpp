#include <iostream>
#include <cmath>
using namespace std;

void palindrome(int n, int num)
{
  int n1, n2;

  n1 = num / pow(10,(n/2));
  n2 = num % pow(10,(n/2));

  n2 = (n2 % pow(10, n/4))*10 + (n2 / pow(10, n/4);

  if(n1==n2)
    cout << num << endl;
}

int main()
{
  int number;
  cin >> number;


}
