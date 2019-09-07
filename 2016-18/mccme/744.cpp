#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
  char operation;
  cin >> operation;
  string input;
  unordered_set<string> stringList;
  while (operation != '#') {
    if (operation == '+') {
      cin >> input;
      if (stringList.find(input) == stringList.end())
        stringList.insert(input);
    }

    if (operation == '?') {
      cin >> input;
      if (stringList.find(input) == stringList.end())
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    }

    if (operation == '-') {
      cin >> input;
      stringList.erase(stringList.find(input));
    }

    cin >> operation;
  }
  return 0;
}
