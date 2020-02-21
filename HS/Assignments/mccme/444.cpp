#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  double d = 2 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));

  double x0 = (pow(x1, 2) + pow(y1, 2)) * (y2 - y3) +
              (pow(x2, 2) + pow(y2, 2)) * (y3 - y1) +
              (pow(x3, 2) + pow(y3, 2)) * (y1 - y2);
  x0 /= d;

  double y0 = (pow(x1, 2) + pow(y1, 2)) * (x3 - x2) +
              (pow(x2, 2) + pow(y2, 2)) * (x1 - x3) +
              (pow(x3, 2) + pow(y3, 2)) * (x2 - x1);
  y0 /= d;
  double r = sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2));
  cout << setprecision(10) << x0 << ' ' << y0 << ' ' << r << endl;
  return 0;
}
