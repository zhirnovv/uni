#include <iostream>
using namespace std;

int main()
{
	int x, k = 1;
	long long int a = 1, i = 1, j = 1;
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
}
