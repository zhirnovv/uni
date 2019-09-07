#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, querynum;
  cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  cin >> querynum;
  for(int i = 0; i < querynum; i++)
  {
    int left, right, max = -1, index;
    cin >> left >> right;

    for(int i = left-1; i < right; i++)
      if(arr[i] > max)
      {
        max = arr[i];
        index = i;
      }
    cout << max << ' ' << index+1 << endl;
  }
}
