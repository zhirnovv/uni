#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int number, weight, price, mass;
  cin >> mass;
  cin >> number;
  int weightnum[number];
  int pricenum[number];
  for(int i = 0; i < number; i++)
    {
      cin >> weightnum[i];
      cin >> pricenum[i];
    }
  int maxvalue[mass+1];
  maxvalue[0] = 0;
  for (int i = 1; i <= mass; i++)
  {
    maxvalue[i] = maxvalue[i-1];
		for (int j = 0; j < number; j++)
		{
			if (weightnum[j] <= i)
			{
				maxvalue[i] = max(maxvalue[i], maxvalue[i - weightnum[j]] + pricenum[j]);
			}
		}
  }
  cout << maxvalue[mass];
  return 0;
}
