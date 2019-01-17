#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

  std::vector<int> div(9, 0);

  int n, number, pairs;
  cin >> n;

  for (size_t i = 0; i < n; i++) {
    cin >> number;
    div[number%9]++;
  }

  pairs = div[0]*(div[0]-1)/2;
  for (size_t i = 1; i < 4; i++) {
    pairs += div[i] * div[9 - i];
  }

  cout << pairs << endl  ;
  return 0;

}
