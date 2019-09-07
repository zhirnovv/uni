#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[]) {

  double days_above_zero = 0, first_day_above_zero, above_zero_temp = 0, lowest_temp = 65535, highest_temp = -65535,
  temp_median, highest_temp_jump_day, highest_temp_jump, average_temp, average_temp_days = 0, average_temp_delta = 2, most_average_day, longest_stability_period;

  std::vector<int> days(28);

  for (size_t i = 0; i < 28; i++) {
    cin >> days[i];
  }

  average_temp = accumulate(days.begin(), days.end(), 0) / 28;

  for (size_t i = 0; i < 28; i++) {

    if (days[i] > 0) {
      above_zero_temp++;
      days_above_zero++;
    }
    if (above_zero_temp == 1) {
      first_day_above_zero = i+1;
    }

    if (days[i] > highest_temp) {
      highest_temp = i+1;
    }

    if (days[i] < lowest_temp) {
      lowest_temp = i+1;
    }

    if (days[i] >= average_temp-1 && days[i] <= average_temp+1) {
      average_temp_days++;
      if (abs(days[i] - average_temp) < average_temp_delta) {
        average_temp_delta = abs(days[i] - average_temp);
      }
    }


  }

  temp_median = highest_temp - lowest_temp;



  return 0;
}
