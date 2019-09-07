// ---Merge sort---
// O(NlogN) complexity
// Merge sort uses the divide and conquer strategy.
// The main concept of merge sort is consecutively dividing the array in halves
// and merging them back together into a sorted array

#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

void merge(int *arr, int left, int middle, int right)
{
    int i, j, k;
    int sizeL = middle - left + 1;
    int sizeR = right - middle;

    int arrL[sizeL], arrR[sizeR]; // create left and right sub arrays

    for (i = 0; i < sizeL; i++)
        arrL[i] = arr[left + i]; // copy left part of arr to arrL
    for (j = 0; j < sizeR; j++)
        arrR[j] = arr[middle + 1 + j];

    // We will now merge the arrays back together
    i = 0;    // initial index of left subarray
    j = 0;    // initial index of right subarray
    k = left; // initial index of merged subarray

    while (i < sizeL && j < sizeR)
    {
        if (arrL[i] <= arrR[j])
        {
            arr[k] = arrL[i];
            i++;
        }
        else
        {
            arr[k] = arrR[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of subarrays
    while (i < sizeL)
    {
        arr[k] = arrL[i];
        i++;
        k++;
    }
    while (j < sizeR)
    {
        arr[k] = arrR[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2; // calculate middle index of subarray

        // Recursively sort left and right subarrays
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right); //merge sorted subarrays back together
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
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}