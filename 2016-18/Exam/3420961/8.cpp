#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

int main(int argc, char const *argv[]) {

  int n, x, y, posx_max = 0, posx_min = 10000000, negx_max = -10000000,
               negx_min = 0, posy_max = 0, negy_max = 0;

  cin >> n;

  for (size_t i = 0; i < n; i++) {
    cin >> x >> y;
    if (x > 0) {
      if (y == 0) {
        posx_max = max(posx_max, x);
        posx_min = min(posx_min, x);
      } else
        posy_max = max(posy_max, abs(y));
    }
    if (x < 0) {
      if (y == 0) {
        negx_max = max(negx_max, x);
        negx_min = min(negx_min, x);
      } else
        negy_max = max(negy_max, abs(y));
    }
  }

  double output =
      max((posx_max - posx_min) * posy_max, (negx_max - negx_min) * negy_max);

  cout << output/2;
  return 0;
}
