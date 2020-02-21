#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

  int cnt;
  cin >> cnt;
  string name, surname, participator;
  int points1, points2, points3, maxpoints=0;
  std::vector<string> v;

  for (size_t i = 0; i < cnt; i++) {
    cin >> name >> surname >> points1 >> points2 >> points3;
    participator = name + ' ' + surname;
    if ((points1+points2+points3) > maxpoints) {
      v.clear();
      v.push_back(participator);
      maxpoints = points1+points2+points3;
    }
    else if((points1+points2+points3) == maxpoints)
      v.push_back(participator);
  }

  for (size_t i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }

  return 0;
}
