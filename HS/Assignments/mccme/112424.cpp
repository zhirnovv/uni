#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
 long n;
 cin >> n;
 map<long, long> mp;
 for (int i = 0; i < n; i++) {
 long ch, ca, re;
 cin >> ch >> ca;
 re = ca%ch;
 if (re == 0) {
 continue;
 }
 else if (mp.find(re) != mp.end()) {
 mp[re]++;
 }
 else {
 mp[re] = 1;
 }
 }

 int max = 0;
 int maxe = 0;
 for (auto e : mp) {
 if (e.second > max) {
 max = e.second;
 maxe = e.first;
 }
 else if (e.second == max && e.first > e.second) {
 max = e.second;
 maxe = e.first;
 }
 }

 cout << maxe << endl;

 return 0;
}
