#include <iostream>
#include <string>
using namespace std;

int main() {
  string conveyor = "S";
  int input;
  cin >> input;
  for (int i = 0; i < input; i++) {
    int size = conveyor.size();
    for (int j = size-1; j >= 0; j--) {
      if (conveyor[j] == 'S') {
        conveyor[j] = 'G';
      } else {
        if (conveyor[j] == 'G') {
          conveyor[j] = 'P';
        } else {
          if (conveyor[j] == 'P') {
            conveyor[j] = 'S';
            conveyor.insert(j + 1, "G");
          }
        }
      }
    }
  }
  cout << conveyor;
  return 0;
}
