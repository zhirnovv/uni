#include <iostream>
using namespace std;
#define N 30
int main(void) {
  int a[N];
  int i, x, y;
  float s;
  for (i = 0; i < N; i++)
    cin >> a[i];
  x = 0;
  y = 0;
  for (i = 0; i < N; i++) {
    if (a[i] > 50) {
      x += a[i];
      y++;
    }
  }
  s = x / y;
  cout << s;
  return 0;
}
