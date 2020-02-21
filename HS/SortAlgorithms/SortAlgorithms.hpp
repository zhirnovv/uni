#ifndef SORT_HPP
#define  SORT_HPP

#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

int* BubbleSort(int arr[], int n)//arr is the array that requires sorting, n is the length of the array
{
  for(int i=0; i<(n-1); i++)
  {
    for(int j=0; j<(n-i-1); j++)
        if(arr[j]<arr[j+1])
          swap(arr[j], arr[j+1]);
  }

  return arr;
}

int* InsertSort(int arr[], int n)//arr is the array that requires sorting, n is the length of the array
{
  for(int i=1; i<n; i++)
  {
    int j = i-1;
    while(j >= 0 && arr[j]>arr[j+1])
    {
      swap(arr[j],arr[j+1]);
      j--;
    }
  }

  return arr;
}

int* SelectSort(int arr[], int n)//arr is the array that requires sorting, n is the length of the array
{
  for(int i=0; i<n-1; i++)
    {
      int min = i;

      for(int j = i+1; j<n; j++)
        if(arr[j] < arr[min])
          min = j;

      if(min != i)
        swap(arr[min], arr[i]);
    }

  return arr;
}

void Heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i;
    int r = 2*i + 1;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n)//arr is the array, n is length
{
  for(int i = n/2 - 1; i>=0; i--)
    Heapify(arr, n, i);

  for(int i=n-1; i>=0; i--)
  {
    swap(arr[i], arr[0]);
    Heapify(arr, i, 0);
  }
}

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




#endif
