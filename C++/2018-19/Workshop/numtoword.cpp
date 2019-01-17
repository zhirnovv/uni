#include <iostream>
#include <string>

using namespace std;

string from1to10(int num)
{
    string output = "";
    switch(num) {
        case 1:
            output += "one";
            break;
        case 2:
            output += "two";
            break;
        case 3:
            output += "three";
            break;
        case 4:
            output += "four";
            break;
        case 5:
            output += "five";
            break;
        case 6:
            output += "six";
            break;
        case 7:
            output += "seven";
            break;
        case 8:
            output += "eight";
            break;
        case 9:
            output += "nine";
            break;
    }
    return output;
}

string from10to100(int num)
{
    string output = "";
    switch (num)
    {
        case 11:
            output += "eleven";
            break;
        case 12:
            output += "twelve";
            break;
        case 13:
            output += "thirteen";
            break;
        case 14:
            output += "fourteen";
            break;
        case 15:
            output += "fifteen";
            break;
        case 16:
            output += "sixteen";
            break;
        case 17:
            output += "seventeen";
            break;
        case 18:
            output += "eighteen";
            break;
        case 19:
            output += "nineteen";
            break;
    }
    if(num >= 20 && num < 30) {
        output += "twenty  " + from1to10(num % 10);
    }
    if(num >= 30 && num < 40) {
        output += "thirty " + from1to10(num % 10);
    }
    if(num >= 40 && num < 50) {
        output += "forty " + from1to10(num % 10);
    }
    if(num >= 50 && num < 60) {
        output += "fifty " + from1to10(num % 10);
    }
    if(num >= 60 && num < 70) {
        output += "sixty " + from1to10(num % 10);
    }
    if(num >= 70 && num < 80) {
        output += "seventy " + from1to10(num % 10);
    }
    if(num >= 80 && num < 90) {
         output += "eighty " + from1to10(num % 10);
    }
    if(num >= 90 && num < 100) {
         output += "ninety " + from1to10(num % 10);
    }
    return output;
}

string from100to1000(int num)
{
    string output = "";
    output += from1to10(num / 100) + " hundred " + from10to100(num % 100);

    return output;
}

int main()
{
    int num;
    cin >> num;

    int billions, millions, thousands, hundreds, tens, ones;
    billions = num / 1000000000;
    millions = (num % 1000000000) / 1000000;
    thousands = (num % 1000000) / 1000;
    hundreds = num % 1000;

    if (num == 1000000000)
        cout << "one billion";
    else if(num == 0)
        cout << "zero";
    else
        cout << from100to1000(millions) << " millions " << from100to1000(thousands) << " thousands " << from100to1000(hundreds);

    return 0;
}