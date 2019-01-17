#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, input, min = INT_MAX, index;
  cin >> n;

  std::vector<int> counter(9, 0);

  for (size_t i = 0; i < n; i++) {
    cin >> input;
    counter[std::to_string(input).length() - 1]++;
  }

  for (size_t i = 0; i < 9; i++) {
    if(counter[i] != 0)
      min = std::min(counter[i], min);
  }

  for (size_t i = 0; i < 9; i++)
    if (counter[i] == min && counter[i] != 0) {
      index = i + 1;
      cout << index << ' ' << counter[i];
      break;
    }
  return 0;
}
