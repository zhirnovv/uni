#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "../Digit/Digit.h"
#include "IOManager.h"

IOManager::IOManager(std::string inFilePath, std::string outFilePath) {
  inFile.open(inFilePath);
  outFile.open(outFilePath);

  if (!inFile.good()) {
    throw "IOManager Error: could not open infile";
  }
  
  if (!outFile.good()) {
    throw "IOManager Error: could not open outfile";
  }
  
  inFile >> rowCount >> rowLength >> phaseCount;
}

IOManager::~IOManager() {
  inFile.close();
  outFile.close();
}

int IOManager::getRowCount() {
  return rowCount;
}

int IOManager::getRowLength() {
  return rowLength;
}

int IOManager::getPhaseCount() {
  return phaseCount;
}

void IOManager::getDigitRow(int rowIndex, Digit *digits) {
  std::string row;

  for(int i = 0; i < rowIndex; i++) {
    std::getline(inFile, row);
  }

  std::getline(inFile, row);
  inFile.seekg(0);
  
  std::stringstream ss;
  ss << row;

  for (int i = 0; i < rowLength; i++) {
    int value;
    ss >> value;

    Digit d;
    d.position = i;
    d.value = value;

    digits[i] = d;
  }
}
