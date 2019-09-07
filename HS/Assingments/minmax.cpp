#include <iostream>
#include <algorithm>

using namespace std;

void minmax(int array[], int length)
{
  for(int i=0; i<length; i++)
    cin >> array[i];

  cout << endl;

  if (length % 2 == 0)
  {
    int max=0;
    int min=2147483647;

    for(int i=0; i<length; i+=2)
      if(array[i] > array[i+1])
        {
          int temp = array[i+1];
          array[i+1] = array[i];
          array[i] = temp;
        }

    for(int i=0; i<length; i+=2)
      if(array[i] < min)
        min = array[i];

    for(int i=1; i<length; i+=2)
      if(array[i] > max)
        max = array[i];

    cout << min << ' ' << max << endl;
  }

  if (length % 2 != 0)
  {
    int max=0;
    int min = array[length];

    for(int i=0; i<length-1; i+=2)
      if(array[i] > array[i+1])
      {
        int temp = array[i+1];
        array[i+1] = array[i];
        array[i] = temp;
      }

    for(int i=1; i<length; i+=2)
      if(array[i] > max)
        max = array[i];

    cout << max << ' ' << min << endl;
  }
}

int main()
{
  int n;
  cin >> n;
  int arr[n];

  minmax(arr, n);

  return 0;
}
