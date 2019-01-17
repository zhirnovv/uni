#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int columns;
    cin >> columns;

    cout << "---1---" << endl;
    for (size_t i = 0; i < columns; i++)
        cout << '*';
    cout << endl;

    cout << "---2---" << endl;
    for (size_t i = 0; i < columns; i++)
        cout << '*' << ' ';
    cout << endl;

    cout << "---3---" << endl;
    for (size_t i = 1; i <= columns; i++)
    {
        for (size_t j = 0; j < i; j++)
            cout << '*';
        cout << endl;
    }

    cout << "---4---" << endl;
    for (size_t i = columns; i > 0; i--)
    {
        for (size_t j = i; j > 0; j--)
            cout << '*';
        cout << endl;
    }

    cout << "---5---" << endl;
    for (size_t i = 1; i < columns + 1; i++)
    {
        for (size_t j = 0; j < columns + 1 - i; j++)
            cout << ' ';
        for (size_t j = 0; j < i; j++)
            cout << '*';
        cout << endl;
    }

    cout << "---6---" << endl;

    for (size_t i = 0; i < columns; i++)
    {
        for (size_t j = 0; j < i; j++)
            cout << ' ';
        for (size_t j = 0; j < columns - i; j++)
            cout << '*';
        cout << endl;
    }

    cout << "---7---" << endl;
    
    int space = 2 * columns - 2; 

    for (int i = 0; i < columns; i++) 
    { 
        for (int j = 0; j < space; j++) 
            cout << " "; 
        space = space - 1; 
        for (int j = 0; j <= i; j++ ) 
            cout << "* "; 
        
        cout << endl; 
    }
    
    return 0;
}