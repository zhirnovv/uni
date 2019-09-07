#include <iostream>
#include <string>

using namespace std;

int main()
{
  string input;
  cin >> input;

  int shiftValue;
  cin >> shiftValue;

  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int alphabetSize = 26;

  for(int i = 0; i < input.length(); i++)
  {
       int asciiVal = input[i] - 'A';

       if(asciiVal - shiftValue < 0)
        input.at(i) = alphabet.at(alphabetSize - (shiftValue - asciiVal));

       else input.at(i) = alphabet.at(asciiVal-shiftValue);
   }

   cout << input;

   return 0;
}
