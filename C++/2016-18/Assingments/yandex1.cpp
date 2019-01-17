#include <iostream>

using namespace std;

int main()
{
  int a, b;
  int cnt=0;

  cin >> a >> b;

  if(a >= b)
    for(int i = b; i <= a; i++)
      if (i%3 == 2)
        cnt++;

  if(a < b)
    for(int i = a; i <= b; i++)
      if (i%3 == 2)
        cnt++;

  cout << cnt;

  return 0;
}
