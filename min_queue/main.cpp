#include <fstream>
#include <iostream>
#include <string>
#include "minStack/minStack.h"
#include "minQueue/minQueue.h"

using namespace std;

int main() {
  ifstream inFile("in.txt");
  ofstream outFile("out.txt");
  MinQueue mq;

  string command;

  if (!inFile.good()) {
    cout << "Error: failed to read file.";
    return 0;
  }

  while (inFile >> command) {
    switch (command[0]) {
    case '+':
      mq.push(stoi(command.substr(1)));
      break;
    case '-':
      mq.pull();
      break;
    case '?':
      outFile << mq.min() << ' ';
      break;
    default:
      cout << "Error: invalid command";
    }
  }

  return 0;
}
