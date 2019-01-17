#include <iostream>

using namespace std;

int Count(int arr[], int n, int price )
{
    if (price < 0)
      return 0;
    if (n <=0 && price >= 1)
      return 0;
    if (price == 0)
      return 1;

  return Count(arr, n - 1, price) + Count(arr, n, price-arr[n-1]);
}

int main()
{
  int n;
  cin >> n;
  int Coins[n];
  for(int i = 0; i < n; i++)
  {
    cin >> Coins[i];
  }
  int sum;
  cin >> sum;

  cout << Count(Coins, n, sum);
  return 0;
}
