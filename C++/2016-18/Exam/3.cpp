#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {

  std::vector<int> alphabet(26, 0);

  string input;
  cin >> input;

  for (size_t i = 0; i < input.size(); i++) {
    if (input[i] >= 'A' && input[i] <= 'Z') {
      alphabet[input[i]-65]++;
    }
    else if (input[i] >= 'a' && input[i] <= 'z') {
      alphabet[input[i]-97]++;
    }
  }

  for (size_t i = 0; i < alphabet.size(); i++) {
    if (alphabet[i]!=0) {
      cout << char(i+97) << alphabet[i] << endl;
    }
  }

  return 0;
}
