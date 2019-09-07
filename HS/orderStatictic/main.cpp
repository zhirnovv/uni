#include <iostream>
#include <algorithm>
#include <array>
using namespace std;


int divide(double *arr, int left, int right) {
  int i, j, x;

  i = left;
  j = right;
  x = arr[(i + j) / 2];

  while (i <= j) {
    while (arr[i] < x)
      i++;
    while (arr[j] > x)
      j--;
    if (i <= j) {
      swap(arr[i++], arr[j--]);
    }
  }
  return j;
}

int f_mvsa(double* a, int N) {
  int left = 0, right = a.size();
  while (true) {
    int mid = divide(a, left, right);

    if (mid == N) {
      return a[mid];
    }
    else if (N < mid) {
      right = mid;
    }
    else {
      N -= mid + 1;
      left = mid + 1;
    }
  }
}
