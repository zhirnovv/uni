#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int goodnumber, n;
  cin >> goodnumber >> n;
  int a[n][n];

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++) {
      if (a[i][j] == goodnumber) {
        cout << "YES" << endl;
        break;
      }
      if (i == n-1) {
        cout << "NO" << endl;
      }
    }
  }

  return 0;
}
