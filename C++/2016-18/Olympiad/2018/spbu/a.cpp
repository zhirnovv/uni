#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
  double x;
  double y;

  bool operator!=(const Point& p) {
		return p.x != x || p.y != y;
  }
};

int main() {
  int n;
  cin >> n;

  if (n < 3){
    cout << "-1" << endl;
    return 0;
  }

	vector <Point> polygon(n);
  cin >> polygon[0].x >> polygon[0].y;
  cin >> polygon[1].x >> polygon[1].y;

  bool on_line = true;
	bool same_x = false;

  double k, b;

  if (polygon[0].x == polygon[1].x) {
    same_x = true;

    if (polygon[0].y != polygon[1].y) {
      on_line = false;
    }
  } else {
    k = (polygon[1].y - polygon[0].y) / (polygon[1].x - polygon[0].x);
    b = polygon[0].y - k * polygon[0].x;
  }

	// y = kx + b
  // y_1 = kx_1 + b
  // y_2 = kx_2 + b
  // b = y_1 - kx_1
  // b = y_2 - kx_2
  // y_1 - kx_1 = y_2 - kx_2
  // k(x_2 - x_1) = y_2 - y_1
  // k = (y_2 - y_1) / (x_2 - x_1)
  // b = y_1 - kx_1

  for (int i = 2; i < n; i++) {
		cin >> polygon[i].x >> polygon[i].y;

    if (same_x && polygon[0] != polygon[i]) {
			same_x = false;
      on_line = false;
    }

    if (!same_x && on_line && (k * polygon[i].x + b - polygon[i].y != 0)) {
      on_line = false;
    }
  }

  if (on_line) {
    cout << "-1" << endl;
    return 0;
  }

  int sign = -1;
  // -1 -- not set
  // 0 	-- positive
  // 1 	-- negative

  for (int i = 0; i < n; i++) {
    int second = (i+1) % n;
    int third = (i+2) % n;
    double pseudoscalar = (polygon[second].x - polygon[i].x) * (polygon[third].y - polygon[second].y) - (polygon[second].y - polygon[i].y) * (polygon[third].x - polygon[second].x);
    int current_sign = signbit(pseudoscalar) ? 1 : 0;

    if (sign == -1) {
    	sign = current_sign;
    } else if (current_sign != sign) {
      cout << "0" << endl;
      return 0;
    }
  }

  cout << "1" << endl;
  return 0;
}
