#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

string ToBinary(int decimal)
{
	int rem;
	string result = "";
	if (decimal <= 1) {
		result += '0' + decimal;
		return result;
	}
	rem = decimal % 2;
	result += ('0' + rem);
	return ToBinary(decimal / 2) + result;
}

int main() {

	string input, output = "";
	cin >> input;
	int number;
	for (int i=0; i<input.size(); i++)
	{
		if (isdigit(input[i]))
		{
			number = input[i] - '0';
			i++;
			while (isdigit(input[i]))
			{
				number = number * 10 + (input[i] - '0');
				i++;
			}
			output += ToBinary(number);
			i--;
		} else
			output += input[i];
	}
	cout << output;
	return 0;
}
