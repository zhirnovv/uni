#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
  double a, b, c, dis;

  cin >> a >> b >> c;

  dis = pow(b, 2) - 4*a*c;

  if (dis == 0) {
    cout << (-1*b)/(2*a);
  }
  else if (dis > 0) {
    cout << ((-1*b)+sqrt(dis))/(2*a) << ((-1*b)-sqrt(dis))/(2*a) << endl;
  }
  return 0;
}
