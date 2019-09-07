#include <iostream>
using namespace std;
#define N 70
int main(void) {
  long a[N];
  long i, j, x, y;
  for (i = 0; i < N; i++)
    cin >> a[i];
  x = 0;
  y = 100000000;
  for (i = 0; i < N; i++) {
    if (a[i] > x) {
      x = a[i];
    }
    if (a[i] < y) {
      y = a[i];
    }
  }
  cout << x - y;
  return 0;
}
