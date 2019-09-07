#include <algorithm>
#include <iostream>
#include <vector>

struct element {
  char letter;
  int counter;
};

bool sortByCounter(const element &a, const element &b) {
  return a.counter > b.counter;
}

using namespace std;

int main(int argc, char const *argv[]) {

  std::vector<element> v(26);

  for (size_t i = 0; i < 26; i++) {
    v[i].letter = i + 65;
    v[i].counter = 0;
  }

  char input;
  cin >> input;

  while (input != 46) {
    if (input >= 'A' && input <= 'Z')
      v[input - 65].counter++;
    else if (input >= 'a' && input <= 'z')
      v[input - 97].counter++;
    cin >> input;
  }

  int max = -1;
  int index;
  for (size_t i = 0; i < 26; i++) {
    if (v[i].counter > max)
    {
      max = v[i].counter;
      index = i;
    }
  }

  cout << v[index].letter << ' ' << v[index].counter << endl;

  return 0;
}
