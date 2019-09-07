#include <iostream>

using namespace std;

struct Query {
  int L, R;
};

void RMQ(int arr[], int n, Query q[], int m) {
  int lookup[n][n];
  for (int i = 0; i < n; i++)
    lookup[i][i] = i;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++)
      if (arr[lookup[i][j - 1]] > arr[j])
        lookup[i][j] = lookup[i][j - 1];
      else
        lookup[i][j] = j;
  }

  for (int i = 0; i < m; i++) {
    int L = q[i].L - 1, R = q[i].R - 1;

    cout << arr[lookup[L][R]] << ' ' << lookup[L][R] + 1 << endl;
  }
}

// Driver program
int main() {
  int num, querynum;
  cin >> num;
  int a[num];
  for (int i = 0; i < num; i++)
    cin >> a[i];
  int n = sizeof(a)/sizeof(a[0]);
  cin >> querynum;
  Query q[querynum];
  for (int i = 0; i < querynum; i++) {
    cin >> q[i].L >> q[i].R;
  }
  int m = sizeof(q)/sizeof(q[0]);
  RMQ(a, n, q, m);
  return 0;
}
