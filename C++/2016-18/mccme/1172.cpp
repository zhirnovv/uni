#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector <int> array(n, 0);
  for(int i = 0; i < n; i++)
    cin >> array[i];
  sort(array.begin(), array.end());
  for(int i = 0; i < n; i++)
    cout << array[i] << ' ';

  return 0;
}
