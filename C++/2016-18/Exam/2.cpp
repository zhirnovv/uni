#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {

  std::vector<int> schools(100, 0);

  int n, school_number, max=0;
  string surname, name;
  cin >> n;

  for (size_t i = 0; i < n; i++) {
    cin >> surname >> name >> school_number;
    schools[school_number]++;
    if (schools[school_number] > max) {
      max = schools[school_number];
    }
  }

  for (size_t i = 1; i < 100; i++) {
    if (schools[i] == max) {
      cout << i << endl;
    }
  }

  return 0;
}
