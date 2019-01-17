#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
  int x1, y1, x2, y2, x3, y3;//1 - A, 2 - B, 3 - C

  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  double ab = sqrt(pow(x2-x1, 2)+pow(y2-y1, 2));
  double ac = sqrt(pow(x3-x1, 2)+pow(y3-y1, 2));
  double bc = sqrt(pow(x3-x2, 2)+pow(y3-y2, 2));

  double x0 = (bc * x1 + ac * x2 + ab * x3) / (ab + bc + ac);
  double y0 = (bc * y1 + ac * y2 + ab * y3) / (ab + bc + ac);

  int a = y1 - y2;
  int b = x2 - x1;
  int c = -x2 * y1 + x1 * y2;

  double r = abs(a*x0 + b*y0 + c)/sqrt(pow(a, 2) + pow(b, 2));

  cout << setprecision(10) << x0 << ' ' << y0 << ' ' << r;

  return 0;
}
