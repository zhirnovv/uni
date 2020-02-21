#include <iostream>
using namespace std;

struct Point {
  int x;
  int y;
};

void determinePosition(int x1, int y1, int x2, int y2, int xp, int yp) {
  int a, b, c;
  a = y1 - y2;
  b = x2 - x1;
  c = x1 * y2 - x2 * y1;

  if ((a * xp + b * yp + c) > 0)
    cout <<  "LEFT";
  else if ((a * xp + b * yp + c) < 0)
    cout << "RIGHT";
  else
    cout << "BOTH";
}

int main(int argc, char const *argv[]) {
  Point bock, kid, carlson;
  cin >> bock.x >> bock.y >> kid.x >> kid.y >> carlson.x >> carlson.y;

  determinePosition(bock.x, bock.y, kid.x, kid.y, carlson.x, carlson.y);

  return 0;
}
