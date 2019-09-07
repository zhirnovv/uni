#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
  const int N = 259;
  const int INF = 100000000;
  int a[N][N], b[N][N];
  pair<int, int> c[N][N];
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char cc;
      cin >> cc;
      a[i][j] = cc - '0';
      b[i][j] = INF;
    }
  }

  b[0][0] = a[0][0];
  for (int i = 0; i < n + 1; ++i) {
    for (int j = 0; j < n + 1; ++j) {
      if (b[i][j] + a[i + 1][j] < b[i + 1][j]) {
        b[i + 1][j] = b[i][j] + a[i + 1][j];
        c[i + 1][j] = std::make_pair(i, j);
      }
      if (b[i][j] + a[i][j + 1] < b[i][j + 1]) {
        b[i][j + 1] = b[i][j] + a[i][j + 1];
        c[i][j + 1] = std::make_pair(i, j);
      }
    }
  }
  char ans[N][N];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ans[i][j] = '-';
    }
  }
  int curX = n - 1, curY = n - 1;
  ans[n - 1][n - 1] = '#';
  while (!(curX == 0 && curY == 0)) {
    ans[curX][curY] = '#';
    int newX = c[curX][curY].first;
    int newY = c[curX][curY].second;
    curX = newX;
    curY = newY;
  }
  ans[0][0] = '#';
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << ans[i][j];
    }
    cout << endl;
  }

  return 0;
}
