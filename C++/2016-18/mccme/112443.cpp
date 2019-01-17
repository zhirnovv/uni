#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

  std::vector<int> letters(26, 0);

  char input;
  cin >> input;

  while(input != '.')
  {
    letters[input - 97]++;
    cin >> input;
  }

  for (int i = 0; i < 26; i++) {
    if(letters[i] != 0){
      char letter = i+97;
      cout << letter << ' ' << letters[i] << endl;
    }
  }

  return 0;
}
