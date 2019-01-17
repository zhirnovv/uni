// #include <iostream>
// #include <cmath>
// #include <iomanip>
//
// using namespace std;
//
// int main(int argc, char const *argv[]) {
//
//   int x0, x1, x2, y0, y1, y2;
//   double a, b, c;
//   cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
//
//   a = ((y1 - y0) / sqrt( (x1-x0)*(x1-x0) + (y1-y0)*(y1-y0) ) + (y2-y0) / sqrt( (x2-x0)*(x2-x0) + (y2-y0)*(y2-y0) ));
//
//   b = ((x0-x1) / sqrt( (x1-x0)*(x1-x0) + (y1-y0)*(y1-y0) ) + (x0-x2) / sqrt( (x2-x0)*(x2-x0) + (y2-y0)*(y2-y0) ));
//
//   c = ((x1 * y0 - x0 * y1) / (sqrt( (x1-x0)*(x1-x0) + (y1-y0)*(y1-y0) )) + (x2*y0 - x0*y2));
//
//   cout << setprecision(7) << a << ' ' << b << ' ' << c;
//
//   return 0;
// }

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {

	int x0, y0, x1, y1, x2, y2;

  cin >> x1 >> y1 >> x0 >> y0 >> x2 >> y2;


	double AB = sqrt(pow(x0 - x1, 2) + pow(y0 - y1, 2));
	double BC = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

	double l = AB / BC;

	double x = (x0 + l * x2) / (1 + l);
	double y = (y0 + l * y2) / (1 + l);

	double a = y - y1;
	double b = x1 - x;
	double c = -x1 * y + x * y1;
	double n = sqrt(a * a + b * b);

	a /= n;
	b /= n;
	c /= n;

  cout << setprecision(7) << a << ' ' << b  << ' ' << c;
	return 0;
}
