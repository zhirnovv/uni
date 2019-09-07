#include <iostream>
#include <ctime>
#include "SortAlgorithms.hpp"

using namespace std;

int main()
{
  srand(time(0));

  int length;
  cin >> length;

  int arr[length];

  for(int i=0; i<length; i++)
    arr[i] = rand() % 100;

  int* bubblearr = BubbleSort(arr, length);
  cout << "Bubblesorted array:" << endl;
  for(int i=0; i<length; i++)
      cout << bubblearr[i] << ' ';
  cout << endl;


  int* insertarr = InsertSort(arr, length);
  cout << "Insertsorted array:" << endl;
  for(int i=0; i<length; i++)
      cout << insertarr[i] << ' ';
  cout << endl;

  int* selectarr = SelectSort(arr, length);
  cout << "Selectsorted array:" << endl;
  for(int i=0; i<length; i++)
      cout << selectarr[i] << ' ';
  cout << endl;

  Quicksort(arr, 0, length-1);
  cout << "Quicksorted array:" << endl;
  for(int i=0; i<length; i++)
      cout << arr[i] << ' ';
  cout << endl;

  HeapSort(arr, length);
  cout << "Heapsorted array:" << endl;
  for(int i=0; i<length; i++)
      cout << arr[i] << ' ';
  cout << endl;

  cout << "Mergesorted array:" << endl;
  for(int i=0; i<length; i++)
      cout << arr[i] << ' ';
  cout << endl;

  return 0;
}
