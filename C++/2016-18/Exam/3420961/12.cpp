#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, input, max2 = 0, max11 = 0, max22 = 0, max = 0;

  cin >> n;
  for (size_t i = 0; i < n; i++) {
    cin >> input;
    if (input % 22 == 0) {
      if (max22 > max) {
        max = max22;
      }
      max22 = std::max(max22, input);
    } else if (input % 2 == 0 && input % 11 != 0) {
      max2 = std::max(max2, input);
    } else if (input % 11 == 0 && input % 2 != 0) {
      max11 = std::max(max11, input);
    } else
      max = std::max(max, input);
  }

  int output;
  if (max2 * max11 > max22 * max) {
    output = max2 * max11;
  } else
    output = max22 * max;

  cin >> input;

  cout << "Вычисленное контрольное значение: " << output << endl;
  if (output == input)
    cout << "Контроль пройден";
  else
    cout << "Контрль не пройден";

  return 0;
}
