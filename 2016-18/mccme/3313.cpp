#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int querynum;
  cin >> querynum;

  for (int i = 0; i < querynum; i++) {
    int cnt = 0, left, right;
    cin >> left >> right;
    for (int j = left - 1; j <= right - 1; j++) {
      if (arr[j] == 0) {
        cnt++;
      }
      else continue;
    }

    cout << cnt << ' ';
  }
  return 0;
}
