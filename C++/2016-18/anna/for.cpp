#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int i, j;
  cin >> i >> j;
  int array[i][j];
  for(int i = 0; i < 10; i++)
   for(int j = 0; j < 10; j++)
    array[i][j]= 0;

  for(int i = 0; i < 10; i++)
  {
   for(int j = 0; j < 10; j++)
   {
      cout << array[i][j] << ' ';
   }
   cout << endl;
  }

  return 0;
}
