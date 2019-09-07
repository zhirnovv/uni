#include <iostream>
using namespace std;
#define N 70
int main() {
  int a[N];
  int i, j, m;
  for (i = 0; i < N; i++)
    cin >> a[i];
  m = 10001;
  for (i = 0; i < N; i++) {
    if (a[i] < m && a[i] % 10 == 7 && a[i] > 0) {
      m = a[i];
    }
  }
  cout << m;
  return 0;
}
