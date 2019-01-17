#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int Fib[10000];
  Fib[0] = 1;
  Fib[1] = 1;
  int i;
  if(n == 1 || n == 2)
    cout << '1';
  else
  {
    for (i = 2; i < n; i++)
      Fib[i] = Fib[i-1] + Fib[i-2];
    cout << Fib[n-1] << endl;
    cout << i << endl;
  }
  return 0;
}
