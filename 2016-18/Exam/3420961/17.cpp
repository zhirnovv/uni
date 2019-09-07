#include <cmath>
#include <iostream>
#include <limits>
using namespace std;

int main(int argc, char const *argv[]) {
  int n, x, y, xmax = INT_MIN, xmin = INT_MAX, ymax = 0, ymin = 0, area;

  cin >> n;
  for (size_t i = 0; i < n; i++) {
    cin >> x >> y;
    if (y == 0) {
      xmax = max(xmax, x);
      xmin = min(xmin, x);
    } else {
      ymax = max(ymax, y);
      ymin = min(ymin, y);
    }
  }

  if (xmax > xmin && ymax > 0 && ymin < 0) {
    area = (xmax - xmin) * (ymax - ymin) / 2;
  } else
    area = 0;

  cout << area << endl;

  return 0;
}
