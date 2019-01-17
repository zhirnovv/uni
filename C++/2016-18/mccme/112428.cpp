#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct pupil {
  string name;
  string surname;
  int school;
  int points;
};

int main(int argc, char const *argv[]) {


  int counter, max = -1;
  cin >> counter;

  vector<pupil> v;

  pupil input;

  for (size_t i = 0; i < counter; i++) {
    cin >> input.name >> input.surname >> input.school >> input.points;
    if (input.points > max) {
      max = input.points;
    }
    if(input.school == 50)
    {
      if(input.points > max)
      {
        v.clear();
        v.push_back(input);
        max = input.points;
      }
      else if(input.points == max)
      {
        v.push_back(input);
      }
    }
  }

  if(v.size() <= 2)
    for (size_t i = 0; i < v.size(); i++) {
      cout << v[i].name << ' ' << v[i].surname << endl;
    }
  else cout << v.size();

  cout << endl;

  return 0;
}
