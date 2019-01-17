#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int array[n];

  for(int i=0; i<n; i++)
      cin >> array[i];

  int k,i;
  cin >> k;

  int l=0, u=n-1;
  while(u >= l)
  {
    i = (l+u)/2;
    if (k < array[i])
      u = i-1;
    else if(k > array[i])
      l = i+1;
    else break;
  }
  cout << i;

  return 0;
}
