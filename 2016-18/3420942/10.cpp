#include <iostream>
using namespace std;
const int N = 30;
int main() {
  long a[N];
  long i, j, k;
  for (i = 0; i < N; i++)
    cin >> a[i];

  k = 0;
  for (i = 0; i < N; i++) {
    if (a[i] > 100 && a[i] % 5 == 0) {
      k++;
    }
  }
  for (i = 0; i < N; i++) {
    if (a[i] > 100 && a[i] % 5 == 0) {
      a[i] = k;
    }
  }

  for (i = 0; i < N; i++) {
    cout << a[i] << ' ';
  }


  return 0;
}
