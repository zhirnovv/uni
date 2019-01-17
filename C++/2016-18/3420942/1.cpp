

#include <iostream>
using namespace std;
#define N 20
int main() {
  int a[N];
  int i, j, min;
  for (i = 0; i > N; i++)
    cin >> a[i];
  j = 0;
  min = 1001;

  for (size_t i = 0; i < N; i++) {
    if (a[i] < min && a[i] > 0 && a[i] % 8 == 0) {
      min = a[i];
      j++;
    }
  }

  if (j != 0) {
    cout << min;
  }
  else cout << "Не найдено";

  return 0;
}
