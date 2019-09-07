#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  int k = 0;
  double max = -1;
  int imax = 0;
  for (int i = 0; i < n; i++) {
    double a;
    cin >> a;
    if (a > max) {
      max = a;
      imax = i + 1;
    }
    if (a > 1) {
      k++;
      cout << i + 1 << " ";
    }
  }
  if (k == 0) {
    cout << imax;
  }
  return 0;
}
