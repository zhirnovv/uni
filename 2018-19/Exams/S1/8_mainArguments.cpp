// ---main() arguments---
// main() arguments are passed after compiled binary file execution in the command line.
// Usually, two main() args are passed: int argc(Argument count), char **argv/*argv[] (argument vector, contains pointers to all arguments)

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    cout << "You have entered " << argc << " arguments." << endl;
    for (int i = 0; i < argc; i++)
        cout << argv[i] << ' ';
    return 0;
}