#include <iostream>

using namespace std;

void deleteObj(int * mass, int size, int index)
{
  for (int i = index; i < size - 1; i++)
  {
    mass[i] = mass[i + 1];
  }
}

int main()
{
  int mass[1001];
  int n = 0;
  int countdestroyed = 0;
  int ball;

  while (cin >> ball)
  {
    mass[n++] = ball;
  }

  bool contin = true;
  
  while (contin == true)
  {
    contin = false;
    for (int i = 0; i < n - 2; i++)
    {
      int length = 3;
      if (mass[i] == mass[i + 1] && mass[i + 1] == mass[i + 2])
      {
        contin = true;
        int j = i + 3;
        while (j < n)
        {
          if (mass[j] == mass[j - 1])
          {
            length++;
          }
          else
          {
            break;
          }
          j++;
        }
        for (int s = 0; s < length; s++)
        {
          deleteObj(mass, n, i);
          n--;
          countdestroyed++;
        }
      }
    }
  }

  cout << countdestroyed;
  return 0;
}
