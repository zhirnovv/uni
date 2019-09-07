#include <iostream>
using namespace std;
struct Point {
  int x;
  int y;
};

bool onHalfArea(Point p, Point q, Point r) {
  if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) &&
      q.y >= min(p.y, r.y))
    return true;

  return false;
}

int direction(Point p, Point q, Point r) {
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

  if (val == 0)
    return 0;

  return (val > 0) ? 1 : 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
  int o1 = direction(p1, q1, p2);
  int o2 = direction(p1, q1, q2);
  int o3 = direction(p2, q2, p1);
  int o4 = direction(p2, q2, q1);

  if (o1 != o2 && o3 != o4)
    return true;

  if (o1 == 0 && onHalfArea(p1, p2, q1))
    return true;

  if (o2 == 0 && onHalfArea(p1, q2, q1))
    return true;

  if (o3 == 0 && onHalfArea(p2, p1, q2))
    return true;

  if (o4 == 0 && onHalfArea(p2, q1, q2))
    return true;

  return false;
}
int main() {
  int x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  if (doIntersect({x1, y1}, {x2, y2}, {x3, y3}, {x4, y4})) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
