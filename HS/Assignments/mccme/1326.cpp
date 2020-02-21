#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
void palindrome_detection(string s) {
  int l = 0, r = -1, k;
  int n = (int)s.length();
  vector<int> pal(n);
  for (int i = 0; i < n; i++) {
    if (i > r)
      k = 1;
    else
      k = min(pal[l + r - i], r - i);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
      k++;
    pal[i] = k;
    if (i + k - 1 > r)
      r = i + k - 1, l = i - k + 1;
  }
  for (int i = 0; i < n; i++) {
    cout << pal[i] + pal[i] - 1 << " ";
  }
}

int main() {
  string s;
  cin >> s;
  palindrome_detection(s);
  return 0;
}
