#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, temp;
  cin >> n;
  for (size_t i = 0; i < n; i++) {
    cin >> temp;
    if (temp == 0) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
