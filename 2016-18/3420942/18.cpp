#include <iostream>
using namespace std;
#define N 2014
int main() {
  int a[N];
  int i, j, k;
  for (i = 0; i < N; i++)
    cin >> a[i];
  k = 0;
  if (a[0] < a[1]) {
    k++;
  }
  for (i = 1; i < N-1; i++) {
    if (a[i] < a[i-1] && a[i] > a[i+1]) {
      k++;
    }
  }
  if (a[N-1] < a[N-2]) {
    k++;
  }
  cout << k;
  return 0;
}
