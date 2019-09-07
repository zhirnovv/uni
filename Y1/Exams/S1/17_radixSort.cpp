// ---Radix sort---
// O(nk) complexity
// Radix sort is a non-comparative sort algorithm, which sorts every item in an array
// via sorting them out by every digit starting from first to maximum

#include <iostream>
using namespace std;

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int getMax(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countSort(int *arr, int n, int digit)
{
    int output[n]; // output array
    int i, count[10] = {0};

    // store number occurencies in count array
    for (i = 0; i < n; i++)
        count[(arr[i] / digit) % 10]++;

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Compile the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / digit) % 10] - 1] = arr[i];
        count[(arr[i] / digit) % 10]--;
    }

    // Сopy output into arr
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int *arr, int n)
{
    // Find maximum number to know maximum number of digits
    int max = getMax(arr, n);

    // Individually sort every digit in every number
    for (int digit = 1; max / digit > 0; digit *= 10)
        countSort(arr, n, digit);
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
    radixSort(arr, n);
    printArray(arr, n);
    return 0;
}