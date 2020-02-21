#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> sum_fee_calc;
  for (int i = 0; i < n; i++) {
    double x;
    cin >> x;
    sum_fee_calc.push(x);
  }
  double s = 0, a, b;
  for (int i = 0; i < n - 1; i++) {
    a = sum_fee_calc.top();
    sum_fee_calc.pop();
    b = sum_fee_calc.top();
    sum_fee_calc.pop();
    s = s + ((a + b) / 20);
    sum_fee_calc.push(a + b);
  }
  cout << s;
  return 0;
}
