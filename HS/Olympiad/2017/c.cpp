#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int input;
  cin >> input;

  vector<char> conveyor(1);
  conveyor[0] = 'S';

  if(!input)
    {
      cout << 'S' << endl;
      return 0;
    }

  else
    while(input > 0)
      {
        for(int i = conveyor.size()-1; i != 0; i--)
        {
          if(conveyor[i] == 'S')
            conveyor[i] = 'G';
          if(conveyor[i] == 'G')
            conveyor[i] = 'P';
          if(conveyor[i] == 'P')
          {
            conveyor[i] = 'S';
            conveyor.push_back('G');
          }
        }
        input--;
      }
    for(int i = 0; i < conveyor.size(); i++)
      cout << conveyor[i];
    cout << endl;
    return 0;
}
