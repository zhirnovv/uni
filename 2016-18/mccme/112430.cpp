#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int xmin = 1000000000;
  int xmax = -1000000000;
  int ymax = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (y == 0) {
      xmax = max(x, xmax);
      xmin = min(x, xmin);
    }
    ymax = max(ymax, abs(y));
  }
  cout << 0.5 * (xmax - xmin) * ymax;
  return 0;
}
