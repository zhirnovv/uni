#include <fstream>
#include <iostream>
#include <string>
#include "./Digit/Digit.h"
#include "./IOManager/IOManager.h"

void selectionSort(Digit* row, int rowLength);

int main() {
  try {
    IOManager io("in.txt", "out.txt");
    int rowCount = io.getRowCount();
    int rowLength = io.getRowLength();
    int phaseCount = io.getPhaseCount();
    std::cout << rowCount << ' ' << rowLength << ' ' << phaseCount << std::endl;

    Digit row[rowLength];
    io.getDigitRow(rowCount, row);
    selectionSort(row, rowLength);

    for (int currentPhase = 1; currentPhase < phaseCount; currentPhase++) {
      Digit tempRow[rowLength];
      io.getDigitRow(rowCount - currentPhase, tempRow);
      for (int i = 0; i < rowLength; i++) {
        row[i] = tempRow[row[i].position];
      }
      selectionSort(row, rowLength);
    }

    for (int i = 0; i < rowLength; i++) {
      std::cout << row[i].value << row[i].position << std::endl;
    }

  } catch (const char *error) {
    std::cout << error << std::endl;
  }

  return 0;
}

void selectionSort(Digit *row, int rowLength) {
  int positions[10] = {0};
  for (int i = 0; i < rowLength; i++) {
    positions[row[i].value]++;
  }

  int leadValue = 0;
  for (int i = 0; i < 10; i++) {
    positions[i] += leadValue;
    leadValue = positions[i];
  }

  for (int i = 9; i >= 0; i--) {
    positions[i + 1] = positions[i];
  }
  positions[0] = 0;

  Digit sortedRow[rowLength];
  for (int i = 0; i < rowLength; i++) {
    Digit currentDigit = row[i];

    sortedRow[positions[currentDigit.value]++] = currentDigit;
  }

  for (int i = 0; i < rowLength; i++) {
    row[i] = sortedRow[i];
  }
}
