#include <iostream>
using namespace std;

int main()
{
	long long int x, k = 1, a = 1, i = 1, j = 1;
	cin >> x;
	while (k < x) {
		i++;
		j++;
		if (i * i < j * j * j) {
			a = i * i;
			j--;
		}
		else if (i * i > j * j * j) {
			a = j * j * j;
			i--;
		}
		else {
			a = i * i;
		}
		k++;
	}
	cout << a << endl;
  return 0;
}
