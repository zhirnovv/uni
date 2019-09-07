#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
  int n;
  float area = 0;
  cin >> n;

  vector<int> matx(n+1);
  vector<int> maty(n+1);

  for(int i = 0; i < n; i++)
    cin >> matx[i] >> maty[i];

  matx[n] = matx[0];
  maty[n] = maty[0];

  for(int i = 0; i < n; i++)
    area = area + matx[i]*maty[i+1] - matx[i+1]*maty[i];

  cout << setprecision(2) << abs(area)/2;
  return 0;
}
