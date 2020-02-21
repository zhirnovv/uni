#include <iostream>
using namespace std;

int f(int n, int a, int b) {
    if (n > b) return 0;
    if (a <= n && n <= b) return 1;
    return f(2 * n + 1, a, b) + f(2 * n + 2, a, b);
}

int main()
{
  int n, a, b;
  cin >> n >> a >> b;
  cout << f(n, a, b) << endl;
  return 0;
}
