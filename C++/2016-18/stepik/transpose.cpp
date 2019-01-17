#include <iostream>
using namespace std;

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
  int arr[cols][rows];
  for(int i = 0; i < rows; i++)
    for(int j = 0; j < cols; j++)
      m[i][j] = arr[j][i];
  return arr;
}

int main()
{
  unsigned rows = 3, cols = 5;
  int m[rows][cols];
  int ** array = transpose(m, rows, cols);
  for(int i = 0; i < cols; i++)
  {
    for(int j = 0; j < rows; j++)
      cout << array[i][j] << ' ';
    cout << endl;
  }
  return 0;
}
