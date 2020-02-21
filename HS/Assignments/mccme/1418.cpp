#include <iostream>
#include <algorithm>
using namespace std;

void Quicksort(int arr[], int left, int right)
{
  int i, j, x, t;

  i = left;
  j = right;
  x = arr[(i + j)/ 2];

  while (i <= j)
  {
     while (arr[i] < x)
      i++;
     while (arr[j] > x)
      j--;
     if (i <= j)
     {
       swap(arr[i], arr[j]);
       i++;
       j--;
     }
  }

  if (i < right)
    Quicksort(arr, i, right);
  if (j > left)
    Quicksort(arr, left, j);
}

int main()
{
  int n, count=1;
  cin >> n;
  int arr[n];
  for(int i=0; i < n; i++)
    cin >> arr[i];
  Quicksort(arr, 0, n-1);
  for(int i=1; i < n; i++)
    if(arr[i] != arr[i-1])
      count++;
  cout << count;
  return 0;
}
