#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> arr;
  for(int i=0; i < n; i++)
    {
      int input;
      cin >> input;
      arr.push_back(input);
    }
  sort(arr.begin(), arr.end());
  for(int i=0; i<arr.size(); i++)
    cout << arr[i] << ' ';
  return 0;
}
