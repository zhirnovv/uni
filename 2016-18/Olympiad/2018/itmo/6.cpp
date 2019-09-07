#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {

  int n;
  ifstream input;
  ofstream output;
  input.open("input.txt");
  input >> n;
  std::vector<int> v(n);
  for(int i = 0; i < n; i++)
    input >> v[i];
  input.close();

  int maximum = 0;
  int index = -1;

  for(int i = 0; i < n; i++)
   if (maximum > v[i]) {
     maximum = v[i];
     index = i;
   }
  int k = 1;
  int tempK = 1;
  int temp = 0;
  for (int i=0; i<n; i++)
  {
    if (temp < v[i])
    {
      temp = v[i];
      tempK = 1;
    } else
    {
      tempK += 1;
      k = max(k, tempK);
    }
  }
  output.open("output.txt");
  output << k;
  output.close();
  return 0;
}
