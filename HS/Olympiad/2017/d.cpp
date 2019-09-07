#include <iostream>
using namespace std;

int findAdditives(int n, int m, int k) {
    if ((0 < m && m <= n) && (0 < k && k <= n))
        return findAdditives(n, m, k - 1) + findAdditives(n - k, m - 1, k);
    else if (n == 0 && m == 0)
        return 1;
    else
        return 0;
}

int main() {
	int n, k;
  cin >> n >> k;
  cout << findAdditives(k, n, n) << endl;
	return 0;
}
