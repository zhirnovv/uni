#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> res(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  res[0] = 0;
  res[1] = abs(a[1] - a[0]);
  for (int i = 2; i < n; i++) {
    int nrm = abs(a[i] - a[i - 1]) + res[i - 1];
    int mega = 3 * (abs(a[i] - a[i - 2])) + res[i - 2];
    int temp = abs(a[i-1]-a[i-2]);
    if (nrm + temp > mega) {
      res[i] = mega;
    } else {
      res[i] = nrm;
    }
  }

  cout << res[n - 1];
  return 0;
}
