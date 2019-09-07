// ---Quick sort---
// O(n*logn) complexity
// Quick sort implements the divide and conquer strategy. First we divide the array into two parts:
// All elements smaller than chosen pivot go left of the pivot
// All elements larger than chosen pivot go right of the pivot
// This action is then performed recursively on the left and right parts from the pivot, that way the array will be sorted.

#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high]; // pivot is on the right side
    int i = low - 1;       // this will be the future index of the pivot in the partitioned array

    for (int j = low; j <= high - 1; j++) // we will now travel through the array, excluding the pivot
    {
        if (arr[j] <= pivot)
        {
            i++;                  // shift the index of the pivot to the right, free up space for smaller element
            swap(arr[i], arr[j]); // swap whatever is in the index with the element smaller than the pivot
        }
    }
    swap(arr[i + 1], arr[high]); // swap the last element with element index
    return i + 1;
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int part = partition(arr, low, high); // find the partition point
        quickSort(arr, low, part - 1);        // recursively partition element to the left of the partition point
        quickSort(arr, part + 1, high);       // recursively partition element to the right of the partition point
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}