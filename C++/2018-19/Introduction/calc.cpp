#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int add(unsigned long int a, unsigned long int b) { 
    return a + b;
}

int subtract(unsigned long int a, unsigned long int b) {
    return a - b;
}

int multiply(unsigned long int a, unsigned long int b) {
    return a * b;
}

int divide(unsigned long int a, unsigned long int b) {
    return a / b;
}

int power(unsigned long int a, unsigned long int b) {   
    return pow(a, b);
}

int main() {
    unsigned long int a, b;
    string op;
    cin >> a >> op >> b;
    
    switch(op) {
        case "+" : cout << add(a, b) << endl;
                   break;  
        case "-" : cout << subtract(a, b) << endl;
                    break;
        case "*" : cout << multiply(a, b) << endl;
                    break;
        case "/" : cout << divide(a, b) << endl;
                    break;
        case "^" : cout << power(a, b) << endl;
    }

    return 0;
}