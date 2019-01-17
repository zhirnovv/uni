#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

  double a, b, c, r;
  cin >> a >> b >> c >> r;

  double c2 = -r * sqrt(a * a + b * b) + c;

  cout << setprecision(7) << a << ' ' << b << ' ' << c2 << endl;

  return 0;
}
