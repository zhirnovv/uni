#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void prefix_function(string s) {
  int n = (int)s.length();
  vector<int> prefix(n);
  for (int i = 1; i < n; ++i) {
    int j = prefix[i - 1];
    while (j > 0 && s[i] != s[j])
      j = prefix[j - 1];
    if (s[i] == s[j])
      ++j;
    prefix[i] = j;
  }
  if (n % (n - prefix[n - 1]) == 0) {
    cout << (n / (n - prefix[n - 1]));
  } else {
    cout << 1;
  }
}

int main() {
  string s;
  cin >> s;
  prefix_function(s);
  return 0;
}
