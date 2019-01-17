#include <iostream>
using namespace std;

int determineCode(int screenNum, int outputCode)
{
  if (screenNum <= 2)
  {
    outputCode += 1;
    return outputCode;
  }
  else if (screenNum % 10 == 7)
  {
    screenNum -= 5;
    outputCode += 1;
    determineCode(screenNum, outputCode);
  }
  else if (screenNum % 4 == 0)
  {
    int tempCode = determineCode(screenNum/4, outputCode) + determineCode(screenNum/2, outputCode);
    outputCode = outputCode
  }
  else
  {
    screenNum += 1;
    outputCode += 2;
    determineCode(screenNum, outputCode);
  }
}

int main()
{
  int outputCode = 0;
  int screenNum;
  cin >> screenNum;
  cout << determineCode(screenNum, outputCode);
  return 0;
}
