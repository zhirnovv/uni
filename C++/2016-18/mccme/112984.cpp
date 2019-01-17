#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int n;
    deque<int> goblins;
    cin >> n;

    for(int i = 0; i < n; i++){
        char operation;
        cin >> operation;
        if (operation == '+'){
          int goblinID;
          cin >> goblinID;
          goblins.push_back(goblinID);
        }

        else if (operation == '*'){
          int n;
          cin >> n;

          auto position = goblins.begin() + ((goblins.size()+1) / 2);
          position = goblins.insert(position, n);
        }

        else {
          cout << goblins.front() << endl;
          goblins.pop_front();
        }
    }

  return 0;
}
