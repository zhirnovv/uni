#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

  int cnt, max=-99999, temp;
  cin >> cnt;

  std::vector<int> v(cnt);

  for (size_t i = 0; i < cnt; i++) {
    cin >> v[i];
  }

  for (size_t i = 0; i < cnt; i++) {
    if (v[i] > max) {
      max = v[i];
      temp = i;
    }
  }

  cout << temp+1 << endl;

  return 0;
}
