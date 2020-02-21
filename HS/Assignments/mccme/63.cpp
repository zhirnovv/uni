#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, cnt=0, temp;
  cin >> n;
  for (size_t i = 0; i < n; i++) {
    cin >> temp;
    if (temp > 0) {
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}
