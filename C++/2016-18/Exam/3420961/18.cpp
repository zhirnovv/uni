#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct letter{
  int ascii;
  int counter;
};

bool sortByCounter(const letter &a, const letter &b){
  return a.counter < b.counter;
}

int main(int argc, char const *argv[]) {
  char temp;

  std::vector<letter> alphabet(26);

  for (size_t i = 0; i < 26; i++) {
    alphabet[i].ascii = i + 'a';
  }

  cin.get(temp);
  while (temp != '.') {
    if (temp >= 'a' && temp <= 'z') {
      alphabet[int(temp) - 'a'].counter++;
    }
    cin.get(temp);
  }

  sort(alphabet.begin(), alphabet.end(), sortByCounter);

  for (size_t i = 0; i < 26; i++) {
    if (alphabet[i].counter != 0) {
      cout << char(alphabet[i].ascii);
    }
  }


  return 0;
}
