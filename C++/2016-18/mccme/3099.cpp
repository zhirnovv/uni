#include <iostream>
using namespace std;

struct Point {
  int x;
  int y;
};

int determinePosition(int x1, int y1, int x2, int y2, int xp, int yp) {
  int a, b, c;
  a = y1 - y2;
  b = x2 - x1;
  c = x1 * y2 - x2 * y1;
  if ((a * xp + b * yp + c) > 0)
    return 1;
  else if ((a * xp + b * yp + c) < 0)
    return -1;
  else
    return 0;
}

int main(int argc, char const *argv[]) {
  Point A, O, B, P;
  cin >> A.x >> A.y >> O.x >> O.y >> B.x >> B.y >> P.x >> P.y;

  int pos_OA_B = determinePosition(O.x, O.y, A.x, A.y, B.x, B.y);
  int pos_OB_P = determinePosition(O.x, O.y, B.x, B.y, P.x, P.y);
  int pos_OA_P = determinePosition(O.x, O.y, A.x, A.y, P.x, P.y);

  if (pos_OA_B == 1) {
    if ((pos_OA_P == 1 && pos_OB_P == -1) || pos_OA_P == 0 || pos_OB_P == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else if (pos_OA_B == -1) {
    if ((pos_OA_P == -1 && pos_OB_P == 1) || pos_OA_P == 0 || pos_OB_P == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else
    cout << "NO" << endl;

  return 0;
}
