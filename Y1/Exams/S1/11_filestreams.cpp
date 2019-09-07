// ---Filestreams
// Ofstream - output file stream, create and write info to files
// Ifstream - input file stream, read info from files
// Fstream - general file stream, has capabilities of both ofstream and ifstream

// Ofstream/Fstream open() flags:
// ios::app - append mode, all output to the file appends to the end
// ios::ate - Open a file for output and move the read/write control to the end of the file
// ios::in - open a file for reading
// ios::out - open a file for writing
// ios::trunc - if the file already exists, its contents will be truncated before opening file
// Flags can be combined by using OR(|)

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char data[100];

    ofstream outfile;
    outfile.open("file.dat");
    cout << "Writing to file..." << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);  // get name
    outfile << data << endl; // write name into file

    cout << "Enter your age: ";
    cin >> data; // get age
    cin.ignore();
    outfile << data << endl; // write age into file again
    outfile.close();         // close file

    ifstream infile;
    infile.open("file.dat");

    cout
        << "Reading from file..." << endl;

    infile >> data;       // read data
    cout << data << endl; // output data
    infile >> data;       // read data again
    cout << data << endl;

    infile.close();
    return 0;
}