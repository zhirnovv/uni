#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

  int cnt, output=0;
  cin >> cnt;

  vector<int> v(cnt);

  for (size_t i = 0; i < cnt; i++) {
    cin >> v[i];
  }

  for (size_t i = 1; i < cnt-1; i++)
    if (v[i-1] < v[i] && v[i+1] < v[i])
      output++;

  cout << output;

  return 0;
}
