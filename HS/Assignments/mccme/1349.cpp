#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {

  double x1, y1, x2, y2, x3, y3, x4, y4, x0, y0;

  cin >> x1 >> y1 >> x2 >> y2;

  x0 = (x1+x2)/2;
  y0 = (y1+y2)/2;

  x3 = x0 - (y1 - y0);
  x4 = x0 - (y2 - y0);
  y3 = y0 + (x1 - x0);
  y4 = y0 + (x2 - x0);

  cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4;

  return 0;
}
