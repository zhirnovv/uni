#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
  int n;
  cin >> n;

  int arr[n];
  for(int i=0; i<n; i++)
  {
    arr[i] = rand() % 41 - 20;
    cout << arr[i] << ' ';
  }

  int minimal = 2147483647;
  for(int i=0; i<n; i++)
  {
    if (arr[i] < minimal)
      minimal = arr[i];
  }
  int count = 0;
  for(int i=0; i<n; i++)
  {
    if (arr[i] = minimal)
    {
      arr[i] = 1;
      count++;
    }
  }
  for(int i=0; i<n; i++)
    cout << arr[i] << ' ';
  cout << endl;
  cout << count;
  return 0;
}
