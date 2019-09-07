// #include <iostream>
// #include <string>
//
// using namespace std;
//
// int main(int argc, char const *argv[]) {
//
//   int oldest = 2147483647, age, n, oldestcounter = 0;
//   string firstName, lastName, ageStr, outputName, outputAge, tempAge;
//
//   cin >> n;
//   for (size_t i = 0; i < n; i++) {
//     cin >> firstName >> lastName >> ageStr;
//     tempAge = ageStr;
//     ageStr.erase(ageStr.begin()+2);
//     ageStr.erase(ageStr.begin()+4);
//     age = stoi(ageStr);
//
//     if (age < oldest) {
//       oldest = age;
//       oldestcounter = 1;
//       outputName = firstName + ' ' + lastName;
//       outputAge = tempAge;
//     }
//     else if (age == oldest) {
//       oldestcounter++;
//     }
//   }
//
//   if (oldestcounter == 1) {
//     cout << outputName << ' ' << outputAge;
//   }
//   else cout << oldestcounter;
//
//   return 0;
// }

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string name, surname, data;
    cin >> name >> surname >> data;
    int day = (data[0] - '0') * 10 + (data[1] - '0');
    int month = (data[3] - '0') * 10 + data[4] - '0';
    int year = (data[6] - '0') * 1000 + (data[7] - '0') * 100 + (data[8] - '0') * 10 + data[9] - '0';
    int count = 1;
    for (int i = 0; i < n - 1; i++) {
        string n1, n2, data;
        cin >> n1 >> n2 >> data;
        int d = (data[0] - '0') * 10 + (data[1] - '0');
        int m = (data[3] - '0') * 10 + data[4] - '0';
        int y = (data[6] - '0') * 1000 + (data[7] - '0') * 100 + (data[8] - '0') * 10 + data[9] - '0';
        if (y < year) {
            year = y;
            month = m;
            day = d;
            name = n1;
            surname = n2;
            count = 1;
        } else if (y == year) {
            if (m < month) {
                year = y;
                month = m;
                day = d;
                name = n1;
                surname = n2;
                count = 1;
            } else if (m == month) {
                if (d < day) {
                    year = y;
                    month = m;
                    day = d;
                    name = n1;
                    surname = n2;
                    count = 1;
                } else if (d == day)
                    count++;
            }
        }
    }
    if (count == 1) {
        if (month < 10) {
            if (day < 10) {
                cout << name << " " << surname << " 0" << day << ".0" << month << "." << year;
            } else {
                cout << name << " " << surname << " " << day << ".0" << month << "." << year;
            }
        } else {
            if (day < 10) {
                cout << name << " " << surname << " 0" << day << "." << month << "." << year;
            } else {
                cout << name << " " << surname << " " << day << "." << month << "." << year;
            }
        }
    } else {
        cout << count;
    }
    return 0;
}
