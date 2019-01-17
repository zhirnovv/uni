#include <iostream>
#include <string>

using namespace std;

int main()
{
  string input;
  cin >> input;

  int startPoint, endPoint;
  cin >> startPoint >> endPoint;

  for(int i = 0; i < input.size(); i++)
      {
          if(i >= startPoint-1 && i <= endPoint-1)
          {
              cout << input[endPoint-1-(i-(startPoint-1))];
          }
          else
          {
              cout << input[i];
          }
      }
      return 0;
}
