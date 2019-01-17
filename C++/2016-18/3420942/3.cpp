#include <iostream>
using namespace std;
#define N 20
int main() {
  int a[N];
  int i, j, max;
  for (i = 0; i < N; i++)
    cin >> a[i];

  max = 0; j = 0;
  for (i = 0; i < N; i++) {
    if (a[i] > 99 && a[i] < 1000 && a[i] > max && a[i] % 7 != 0) {
      max = a[i];
      j++;
    }
  }
  if (j != 0) {
    cout << max;
  }
  else cout << "не найдено";
  return 0;

}
