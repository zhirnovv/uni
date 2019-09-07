#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int cnt;
  cin >> cnt;

  std::vector<int> v(cnt);

  for (size_t i = 0; i < cnt; i++) {
    cin >> v[i];
  }

  for (size_t i = 1; i < v.size(); i++) {
    if ((v[i] <= -1 && v[i-1] <= -1) || (v[i] >= 0 && v[i-1] >= 0)) {
      cout << "YES";
      return 0;
    }
  }

  cout << "NO";

  return 0;
}
