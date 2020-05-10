#include <fstream>
#include "../Digit/Digit.h"

#ifndef IO_MANAGER
#define IO_MANAGER

class IOManager {
  private: 
    int rowCount, rowLength, phaseCount;
    std::ifstream inFile;
    std::ofstream outFile;
  public:
    IOManager(std::string inFilePath, std::string outFilePath);
    ~IOManager();
    
    int getRowCount(); 
    int getRowLength(); 
    int getPhaseCount();
    void getDigitRow(int rowIndex, Digit * digits);
};

#endif
