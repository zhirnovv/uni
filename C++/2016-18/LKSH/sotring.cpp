#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int pushups = 0;
  int arr[n];
  for(int i=0; i < n; i++)
  {
    cin >> arr[i];
  }
  for(int i=0; i<(n-1); i++)
  {
    for(int j=0; j<(n-i-1); j++)
        if(arr[j]<arr[j+1])
        {
          swap(arr[j], arr[j+1]);
          int diff = arr[j] - arr[j+1];
          pushups += diff;
        }
  }
  cout << pushups * 2;
  return 0;
}
