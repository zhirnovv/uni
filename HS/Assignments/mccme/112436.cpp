#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main(int argc, char const *argv[]) {

  std::vector<int> schools(100, 0);

  int counter;
  cin >> counter;

  string name, surname;
  int school, points, max_points = 0, max_count = 0;

  for (size_t i = 0; i < counter; i++) {
    cin >> name >> surname >> school >> points;
    if(points > max_points)
    {
      max_points = points;
      fill(schools.begin(), schools.end(), 0);
      schools[school]++;
    }
    else if(points == max_points)
    {
      schools[school]++;
    }
  }

  for (size_t i = 0; i < schools.size(); i++) {
    if(schools[i] > max_count)
      max_count = schools[i];
  }

  for (size_t i = 0; i < schools.size(); i++) {
    if (schools[i] == max_count) {
      cout << i << ' ';
    }
  }

  cout << endl;

  return 0;
}
