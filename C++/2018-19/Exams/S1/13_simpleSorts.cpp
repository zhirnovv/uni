#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

// ---Bubble sort---
// O(n^2) complexity
void bubbleSort(int *arr, int n)
{
    int i, j;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// ---Insertion sort---
// O(n^2) complexity
void insertionSort(int *arr, int n)
{
    int i, j, k;
    for (i = 1; i < n; i++)
    {
        k = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > k)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
        printArray(arr, n);
    }
}

// ---Selection sort---
// O(n^2) complexity
void selectionSort(int *arr, int n)
{
    int i, j, min;

    for (int i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[min], arr[i]);
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
    // bubbleSort(arr, n);
    // insertionSort(arr, n);
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}