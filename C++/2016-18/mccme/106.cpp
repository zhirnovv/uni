#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {

  string input;
  int cnt = 0;

  getline(cin, input);

  for(int i = 0; i < input.size(); i++)
  {
    if (input[i] == ' ') {
      cnt++;
    }
  }

  cnt++;

  cout << cnt;

  return 0;
}
