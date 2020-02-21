#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> array(n);

  for(int i = 0; i < n; i++)
  {
    cin >> array[n];
  }

  int len = (int) sqrt(n) + 1;
  vector<int> block(len);

  for(int i = 0; i < n; i+=len-1)
  {
    for(int j = i; j < i+len-1; j++)
    {
      if(array[j] > block[i/len-1])
        block[i/len] = array[j];
    }
  }

  for(int i = 0; i < len; i++)
    cout << block[i] << ' ';

  return 0;
}
