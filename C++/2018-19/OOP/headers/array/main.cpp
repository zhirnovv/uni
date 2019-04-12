#include <iostream>
#include "array.cpp"

using namespace std;

int main()
{
    int n;
    cin >> n;
    int command;
    try
    {
        Array arr(n);
        cout << "Enter command: 1 - get size, 2 - get item, 3 - set item, 0 - exit" << endl;
        cout << "Command: ";
        while (cin >> command)
        {
            switch (command)
            {
            case 1:
                cout << "Array size is: " << arr.getSize() << endl;
                break;
            case 2:
                arr.getItem();
                break;
            case 3:
                arr.setItem();
                break;
            case 0:
                return 0;
            default:
                break;
            }
            cout << "Enter command: 1 - get size, 2 - get item, 3 - set item, 0 - exit" << endl;
            cout << "Command: ";
        }
    }
    catch (int errorCode)
    {
        switch (errorCode)
        {
        case 301:
            cerr << "ERROR 301: Array declaration error: size of array must be a positive integer" << endl;
            return 0;
        case 302:
            cerr << "ERROR 302: Access violation: index out of array bounds" << endl;
        }
    }
    catch (...)
    {
        cerr << "Fatal Error" << endl;
    }

    return 0;
}