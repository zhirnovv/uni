#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int keyAmount;
  cin >> keyAmount;
  vector<int> keys;
  for(int i=0; i < keyAmount; i++)
  {
    int durability;
    cin >> durability;
    keys.push_back(durability);
  }

  int pushes;
  cin >> pushes;
  vector<int> arr;
  for(int i=0; i < pushes; i++)
  {
    int push;
    cin >> push;
    keys[push-1]--;
  }

  for(int i=0; i < keys.size(); i++)
  {
    if(keys[i] >= 0)
      cout << "no" << endl;
    else cout << "yes" << endl;
  }

  return 0;
}
