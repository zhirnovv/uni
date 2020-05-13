#include "./AVLTree/AVLTree.h"
#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ifstream inFile;
  std::ofstream outFile;

  inFile.open("in.txt");
  outFile.open("out.txt");

  if (!inFile.good()) {
    std::cout << "Error: could not find in.txt" << std::endl;
    return 0;
  }

  AVLTree *avl = new AVLTree();

  std::string command;
  while (inFile >> command) {
    int argument;
    if (command == "+") {
      inFile >> argument;
      outFile << avl->insertElement(argument) << std::endl;
      continue;
    }
    if (command == "-") {
      inFile >> argument;
      outFile << avl->deleteElement(argument) << std::endl;
      continue;
    }
    if (command == "?") {
      inFile >> argument;
      outFile << avl->hasElement(argument) << std::endl;
      continue;
    }
    std::cout << "Error: unrecognized command." << std::endl;
    break;
  }

  return 0;
}
