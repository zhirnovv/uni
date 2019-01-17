#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

  string name, deposit, withdraw;
  int n, lockerSize, lockerTime, depositTime, withdrawTime;

  cin >> n >> lockerSize;

  std::vector<string> occupation(lockerSize, "0000");

  for (size_t i = 0; i < n; i++) {
    cin >> name >> deposit >> withdraw;

    withdraw.erase(withdraw.begin() + 2);
    deposit.erase(deposit.begin() + 2);

    depositTime = stoi(deposit);
    withdrawTime = stoi(withdraw);

    for (size_t j = 0; j < 10; i++) {
      lockerTime = stoi(occupation[j]);

      if (depositTime >= lockerTime) {
        occupation[j] = withdraw;
        cout << name << j + 1 << endl;
        break;
      } else
        continue;
    }
  }
  return 0;
}
