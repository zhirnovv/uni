#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool func(pair<string, int> a, pair<string, int> b) {
  return a.second > b.second;
}

int main() {
  int n;
  cin >> n;
  map<string, int> mp;
  vector<pair<string, int>> arr;
  string co;
  getline(cin, co);
  for (int i = 0; i < n; i++) {
    getline(cin, co);
    if (mp.find(co) != mp.end()) {
      mp[co]++;
    } else {
      mp[co] = 1;
    }
  }

  for (auto e : mp) {
    arr.push_back(e);
  }

  sort(arr.begin(), arr.end(), func);
  for (auto e : arr) {
    cout << e.first << endl;
  }
  return 0;
}
