#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int length;
  cin >> length;
  vector <int> arr(length);
  for(int i=0; i < length; i++)
    cin >> arr[i];
  sort(arr.begin(), arr.end());
  for(int i=0; i < length; i++)
    cout << arr[i] << ' ';
  return 0;
}
