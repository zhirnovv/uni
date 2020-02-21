#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
  srand(time(0));
  int n, swap;
  cin >> n;

  int arr[n];
  for(int i=0; i<n; i++)
    {
      cin >> arr[i];
      cout << arr[i] << ' ';
    }
  cout << endl;

  for(int i=0; i<(n-1); i++) //bubblesort, yeah?//
  {
    for(int j=0; i<(n-i-1); j++)
    {
        if(arr[j]>arr[j+1])
        {
          swap = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = swap;
        }
    }
  }
  for(int i=0; i<n; i++)
    cout << arr[i] << ' ';

  return 0;
}
