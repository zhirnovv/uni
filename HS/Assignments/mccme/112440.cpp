#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

bool func1(pair<string, pair<int, int> > a, pair<string, pair<int, int> > b) {
 return a.second.second < b.second.second;
}

bool func2(pair<string, pair<int, int> > a, pair<string, pair<int, int> > b) {
 return a.second.first > b.second.first;
}

int main()
{
 int n;
 cin >> n;

 map<string, pair<int, int> > mp;
 vector<pair<string, pair<int, int> > > arr;
 for (int i = 0; i < n; i++) {
 string name;
 int score;
 bool check = 0;
 cin >> score >> name;
 if (mp.find(name) != mp.end() && score > mp[name].first) {
 mp[name].first = score;
 mp[name].second = i;
 }
 else if(mp.find(name) != mp.end()) {
 continue;
 }
 else {
 mp[name].first = score;
 mp[name].second = i;
 }
 }
 for (auto e : mp) {
 arr.push_back(e);
 }
 sort(arr.begin(), arr.end(), func1);
 sort(arr.begin(), arr.end(), func2);

 cout << "1 place. " << arr[0].first << "(" << arr[0].second.first << ")" << endl;
 cout << "2 place. " << arr[1].first << "(" << arr[1].second.first << ")" << endl;
 cout << "3 place. " << arr[2].first << "(" << arr[2].second.first << ")" << endl;
 return 0;
}
