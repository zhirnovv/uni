#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool checkAvailibility(int x, int y, int k, vector<int> &seats) {
  for (int i = x; i < y; i++) {
    if (seats[i] == k)
      return 0;
  }
  return 1;
}

int main() {
  int n, k, m, x, y;
  cin >> n >> k >> m;
  vector<int> seats(n, 0);
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    if (checkAvailibility(x, y, k, seats) == 1) {
      for (int j = x; j < y; j++)
        seats[j]++;
      cout << "1" << endl;
    } else
      cout << "0" << endl;
  }
  return 0;
}
