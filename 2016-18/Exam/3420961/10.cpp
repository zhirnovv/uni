#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

  vector <int> eng(26, 0);
  vector <int> rus(33, 0);

  string str = "";
  char temp;

  cin.get(temp);
  while (temp != '.') {
    if (temp >= 'A' && temp <= 'Z') {
      eng[temp - 65]++;
    }
    else if (int(temp) >= 192 && int(temp) <= 255) {
      rus[temp-192]++;
    }
    cin.get(temp);
  }

  for (size_t i = 0; i < 26; i++) {
    cout << char(i + 'A') << ' ' << eng[i] << endl;
  }

  for (size_t i = 0; i < 33; i++) {
    wcout << char(i + 192) << ' ' << rus[i] << endl;
  }

  return 0;
}
