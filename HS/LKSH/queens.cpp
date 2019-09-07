#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int n,m,i,j, count=0;
  cin >> n >> m;

  int matrix[n][n];

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      matrix[i][j] = 0;

  for(int f = 0; f < m; f++)
  {
    int x,y;
    cin >> x >> y;
    x--;
    y--;
    int sum = x + y;
    for(int i = 0; i < n; i++)
    {
      matrix[x][i] = 1;
      matrix[i][y] = 1;
    }
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        if(i+j == sum || (i+j % 2 == 1 && x+y % 2 == 1) || x-y == i-j)
          matrix[i][j] = 1;
  }

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      if(matrix[i][j] == 0)
        count++;

  cout << count;
  return 0;
}
