#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct student {
  string Name = "";
  int Points = 0;
};

int main() {
  int n, grade, min1 = 16, min2 = 16, min3 = 16, m = 0;
  string name;
  cin >> n;

  vector<student> students(n);

  for (int i = 0; i < n; ++i) {
    cin >> students[i].Name;
    cin >> name;
    students[i].Name = students[i].Name + ' ' + name;
    for (int j = 0; j < 3; ++j) {
      cin >> grade;
      m += grade;
    }

    if (m < min1) {
      min3 = min2;
      min2 = min1;
      min1 = m;
    } else if (m < min2) {
      min3 = min2;
      min2 = m;
    } else if (m < min3) {
      min3 = m;
    }
    students[i].Points = m;
    m = 0;
  }

  for (int i = 0; i < n; ++i) {
    if (students[i].Points <= min3)
      cout << students[i].Name << endl;
  }
  return 0;
}
