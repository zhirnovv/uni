#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string string1, string2;

  cin >> string1 >> string2;

  int found = string2.find(string1);

  if (found != std::string::npos)
    cout << "yes";
  else
    cout << "no";

  return 0;
}
