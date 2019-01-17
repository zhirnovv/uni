#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    stack<int> stk;
    string input;
    getline(cin, input);
    for (int i = 0; i<input.size(); ++i)
    {
        if (input[i] >= '0' && input[i] <= '9')
            stk.push(input[i] - 48);
        else
        {
            if (input[i] == '+')
            {
                int int1 = stk.top();
                stk.pop();
                int int2 = stk.top();
                stk.pop();
                stk.push(int1 + int2);
            }
            if (input[i] == '-')
            {
                int int1 = stk.top();
                stk.pop();
                int int2 = stk.top();
                stk.pop();
                stk.push(int2 - int1);
            }
            if (input[i] == '*')
            {
                int int1 = stk.top();
                stk.pop();
                int int2 = stk.top();
                stk.pop();
                stk.push(int1 * int2);
            }

        }
    }
    cout << stk.top();
    return 0;
}
