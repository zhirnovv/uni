#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
  int xmin = 2147483647, xmax = -2147483647, ymax = 0, n, x, y;
  double s;

  cin >> n;
  for (size_t i = 0; i < n; i++) {
    cin >> x >> y;
    if (y == 0) {
      xmax = max(x, xmax);
      xmin = min(x, xmin);
    }
    else
    {
      ymax = max(abs(y), ymax);
    }
  }
  s = (double(ymax)*(xmax-xmin))/2;
  cout << s << endl;
  return 0;
}
