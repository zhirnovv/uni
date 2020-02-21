#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int x;
  cin >> x;

  for (size_t i = 1; i <= x; i++) {
    if (x % i == 0) {
      cout << i << ' ';
    }
  }

  cout << endl;

  return 0;
}
