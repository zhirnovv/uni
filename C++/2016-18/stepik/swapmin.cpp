#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

void swap_min(int *m[], unsigned rows, unsigned cols)
{
  int min = m[0][0];
  int minrow = 0;
  for(int i = 0; i < rows; i++)
    for(int j = 0; j < cols; j++)
      if(m[i][j] < min)
        {
          min = m[i][j];
          minrow = i;
        }
  if(minrow != 0)
    {
      for(int j = 0; j < cols; j++)
        swap(m[0][j], m[minrow][j]);
    }
}

int main()
{
  srand(time(0));
  int *m[3];
  for(int i = 0; i < 5; i++)
    m[i] = new int[5];
  unsigned rows = 3, cols = 5;
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      m[i][j] = rand()%101;
      cout << m[i][j] << ' ';
    }
    cout << endl;
  }
  swap_min(m, rows, cols);
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
      cout << m[i][j] << ' ';
    cout << endl;
  }
  return 0;
}
