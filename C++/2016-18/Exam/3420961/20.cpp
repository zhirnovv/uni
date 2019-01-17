#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, input;
  cin >> n;

  std::vector<int> counter(12, 0);

  for (size_t i = 0; i < n; i++) {
    cin >> input;
    counter[input-1]++;
  }

  for (size_t i = 0; i < 12; i++) {
    if (counter[i] > 0) {
      cout << i+1 << ' ' << counter[i] << endl;
    }
  }

  return 0;
}
