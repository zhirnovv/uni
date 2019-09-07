#include <iostream>
#include <string>
using namespace std;

// Array parameters: first, last, current

class Array
{
  private:
    int *array;
    int size;

  public:
    Array(int arraySize)
    {
        cout << "Called parametrized array" << endl;
        if (arraySize < 0)
        {
            cout << "Throwing 301..." << endl;
            throw 301;
        }
        size = arraySize;
        array = new int[arraySize];
    }
    ~Array()
    {
        cout << "Called destructor" << endl;
        size = 0;
        delete[] array;
    }
    Array()
    {
        cout << "Called default constructor" << endl;
        size = 0;
        array = NULL;
    }
    void resetSize(int newSize)
    {
        delete[] array;
        size = newSize;
        array = new int[newSize];
    }
    int getSize()
    {
        return size;
    }
    void getItem()
    {
        int index;
        cout << "Enter index: ";
        cin >> index;
        if (index < 0 || index > size)
        {
            cout << "Throwing 302..." << endl;
            throw 302;
        }
        cout << array[index] << endl;
    }
    void setItem()
    {
        int index;
        cout << "Enter index: ";
        cin >> index;
        if (index < 0 || index > size)
        {
            cout << "Throwing 302..." << endl;
            throw 302;
        }
        int value;
        cout << "Enter value: ";
        cin >> value;
        array[index] = value;
    }
};

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