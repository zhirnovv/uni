#include <iostream>
using namespace std;
#define N 70
int main() {
  int a[N];
  int i, j, x, y;
  for (i = 0; i < N; i++)
    cin >> a[i];

  x = 2147483647;
  for (i = 1; i < N; i++) {
    if ((a[i] + a[i-1]) % 2 == 0 && (a[i] + a[i-1]) < x) {
      x = a[i] + a[i-1];
    }
  }
  cout << x;
  return 0;
}
