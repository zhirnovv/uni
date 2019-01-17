#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, n1 = 0, n2 = 0, n3 = 0, n4 = 0, quantity, x, y;

  cin >> n;
  for (size_t i = 0; i < n; i++) {
    cin >> x >> y;
    if (x > 0 && y > 0) n1++;
    if (x < 0 && y > 0) n2++;
    if (x < 0 && y < 0) n3++;
    if (x > 0 && y < 0) n4++;
  }

  quantity = (n1*n2*(n1+n2-2) + n3*n4*(n3+n4-2)) / 2;

  cout << quantity << endl;

  return 0;
}
