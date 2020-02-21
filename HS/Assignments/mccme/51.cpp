#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
  stack <char> stk;
	int n, i;
	string input;
	cin >> input;

	for(int i=0; i<input.size(); i++)
	{

		if(stk.empty())
		{
			stk.push(input[i]);
			continue;
		}

		if(stk.top()=='['){
			if(input[i]==']')
				stk.pop();
			else
				stk.push(input[i]);
    }
		else if(stk.top()=='{'){
			if(input[i]=='}')
				stk.pop();
			else
				stk.push(input[i]);
    }
		else if(stk.top()=='('){
			if(input[i]==')')
				stk.pop();
			else
				stk.push(input[i]);
    }
	}

	if(stk.empty())
		cout << "yes";
	else
		cout << "no";

	return 0;
}
