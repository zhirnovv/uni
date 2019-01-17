#include <iostream>
using namespace std;
#include <math.h>
#define N 2014
int main() {
  float a[N];
  float d, r;
  int i, j, k;
  for (i = 0; i < N; i++)
    cin >> a[i];

  d = 0;
  for (i = 1; i < N; i++) {
    if (abs(a[i] - a[i-1]) > d) {
      d = abs(a[i] - a[i-1]);
      k = i;
    }
  }

  cout << a[k-1] << ' ' << a[k];
  return 0;
}
