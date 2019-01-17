#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct point {
  double x, y;
  double angle;

  double getAngle() {
    if (x == 0 && y == 0)
      return 5;
    if (x != 0)
      return atan(y / x);
    return M_PI / 2;
  }

  double getRadiusVector() { return sqrt(x * x + y * y); }

  bool operator<(const point &p) const {
    if (this->y == 0 && p.y == 0)
      return this->x < p.x;
    return this->x * p.y < this->y * p.x;
  }
};

void binarySearch(vector<point> &a, int n, point A, int &l, int &r) {
  while (r - l != 1) {
    const int m = l + (r - l) / 2;
    if (A < a[m])
      r = m;
    else
      l = m;
  }
}

bool isClockwise(point A, point B, point C) {
  return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x) < 0;
}

int main() {
  int n;
  cin >> n;
  vector<point> pts(n);
  for (int i = 0; i < n; i++)
    cin >> pts[i].x >> pts[i].y;
  point A;
  cin >> A.x >> A.y;

  int m = 0;
  for (int i = 1; i < n; i++) {
    if (pts[i].y < pts[m].y)
      m = i;
    else if (pts[i].y == pts[m].y && pts[i].x < pts[m].x)
      m = i;
  }
  point zero = pts[m];
  pts.erase(pts.begin() + m);

  A.x -= zero.x;
  A.y -= zero.y;
  A.angle = A.getAngle();
  for (int i = 0; i < n; i++) {
    pts[i].x -= zero.x;
    pts[i].y -= zero.y;
    pts[i].angle = pts[i].getAngle();
    if (A.angle == pts[i].angle) {
      if (A.getRadiusVector() > pts[i].getRadiusVector()) {
        cout << "NO";
        return 0;
      }
    }
  }

  sort(pts.begin(), pts.end());

  int l = 0, r = n - 1;
  binarySearch(pts, n, A, l, r);

  if (isClockwise(pts[r], pts[l], A))
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
