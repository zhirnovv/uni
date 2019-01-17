#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> mus;
  vector<int> muss;
  for (int i = 0; i < n; i++) {
    string a, b;
    char x;
    cin >> a >> b;
    int q = 0;
    for (int j = 1; j <= 10; j++) {
      cin.get(x);
      if (j >= 9) {
        q = q * 10 + int(x) - 48;
      }
    }
    mus.push_back(q);
  }

  sort(mus.begin(), mus.end());
  for (int i = 1; i < mus.size(); i++) {
    if (mus[i] != mus[i - 1]) {
      muss.push_back(mus[i]);
    }
  }
  double x = mus.size();
  double y = muss.size() + 1;
  double z = x / y;
  cout << fixed << setprecision(6) << z;
  return 0;
}
