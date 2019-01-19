// ---Heapsort (Pyramid sort)---
// Complexity: O(NlogN)
// The heap sort bases itself on using a binary heap - a complete binary tree where every parent element is larger(smaller) than its children
// We can represent a binary heap as an array in such a way that
// the left child of a node can be found via 2*i+1, where i is the index of a node
// the right child of a node can be found via 2*i+2, where i is the index of a node

// Algorithm:
// 1. Build a max(min) heap from input
// 2. The largest(smallest) item is now stored in the root of the heap.
// Replace it with the last item of the heap and reduce the size of the heap by 1.
// Heapify the root of the tree.
// 3. Repeat while the size of the heap is greater than 1.

#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

void heapify(int *arr, int n, int i) // n is the size of the array, i is the root of the subtree within the heap
{
    int max = i;           // largest is root
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2; // right child

    // if the left child is larger than the root
    if (left < n && arr[left] > arr[max])
        max = left;

    // if the right child is larger than the root
    if (right < n && arr[right] > arr[max])
        max = right;

    // finally, we check if our root is not the largest
    if (max != i)
    {
        swap(arr[i], arr[max]); // swap the root for the largest element in the subtree
        heapify(arr, n, max);   // and heapify the new subtree
    }
}

void heapSort(int *arr, int n)
{
    // Build the first heap and restructure given array
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // We will now extract element from the element one by one, putting the largest elements in the end
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]); // move current root to the end of the heap
        heapify(arr, i, 0);   // heapify the reduced heap with the new root
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
    heapSort(arr, n);
    printArray(arr, n);
    return 0;
}