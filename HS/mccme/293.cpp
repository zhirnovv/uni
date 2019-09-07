#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int a, b;
  cin >> a >> b;
  if (a > b) {
    cout << 1 << endl;
  }
  else if (a < b) {
    cout << 2 <<  endl;
  }
  else cout << 0 << endl;
  return 0;
}
