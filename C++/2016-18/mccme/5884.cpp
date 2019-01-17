#include <iostream>
#include <vector>
#include <algorithm>

struct alphabet{
  char letter;
  int counter;
};

bool isSmaller(const alphabet &a, const alphabet &b)
{
  return a.counter < b.counter;
}

using namespace std;

int main() {
  // std::vector<int> count(26, 0);
  // std::vector<char> alphabet(26);
  vector<alphabet> v(26);

  char input;
  cin >> input;

  for (int i = 0; i < 26; i++) {
    v[i].letter = i + 97;
  }

  while (input != '.') {
    v[input - 97].counter++;
    cin >> input;
  }

  sort(v.begin(), v.end(), isSmaller);

  for (int i = 0; i < 26; i++) {
    if(v[i].counter != 0)
      cout << v[i].letter << ' ';
  }

  return 0;
}
