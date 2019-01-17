#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool DecreasingOrder(const int a, const int b){
  return a > b;
}

int FindKapConst(string input, int kapconst) {

  sort(input.begin(), input.end());
  string s1 = input;
  sort(input.begin(), input.end(), DecreasingOrder);
  string s2 = input;

  int smallest = stoi(s1);
  int biggest = stoi(s2);

  int diff = biggest - smallest;

  input = to_string(diff);

  if (diff == kapconst) {
    return diff;
  }
  else return FindKapConst(input, diff);
}

int main(){
  string input;
  int kapconst = 0;

  cin >> input;

  int output = FindKapConst(input, kapconst);

  cout << output << endl;

  return 0;
}
