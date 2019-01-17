#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  string a, b, c, d;
  int max1 = 0, max2 = 0, k1 = 0, k2 = 0;
  for (int i = 0; i < n; i++) {
    string q, p;
    int x, y;
    cin >> q >> p >> x >> y;
    if (x == 50) {
      if (y > max1) {
        c = a;
        d = b;
        a = q;
        b = p;
        max2 = max1;
        k2 = k1;
        max1 = y;
        k1 = 1;
        continue;
      }
      if (y == max1) {
        k1++;
        c = q;
        d = p;
        continue;
      }
      if (y < max1 && k1 < 2) {
        if (y > max2) {
          c = q;
          d = p;
          max2 = y;
          k2 = 1;
          continue;
        }
        if (y == max2) {
          k2++;
          continue;
        }
      }
    }
  }
  if (k1 > 2) {
    cout << k1;
    return 0;
  }
  if (k1 == 2) {
    cout << a << " " << b << endl;
    cout << c << " " << d;
    return 0;
  }
  if (k1 == 1) {
    cout << a << " " << b << endl;
    if (k2 == 1) {
      cout << c << " " << d;
      return 0;
    }
  }
  return 0;
}
