#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[]) {

  double a, b, c, min1, min2;
  cin >> a >> b >> c;

  if(a <= b && a <= c)
  {
    min1 = a;
    if(b >= c)
      min2 = c;
    else min2 = b;
    cout << setprecision(10) << sqrt(pow(min1, 2)+pow(min2, 2));
    return 0;
  }

  if(b <= a && b <= c)
  {
    min1 = b;
    if(a >= c)
      min2 = c;
    else min2 = a;
    cout << setprecision(10) << sqrt(pow(min1, 2)+pow(min2, 2));
    return 0;
  }

  if(c <= a && c <= b)
  {
    min1 = c;
    if(a >= b)
      min2 = b;
    else min2 = a;
    cout << setprecision(10) << sqrt(pow(min1, 2)+pow(min2, 2));
    return 0;
  }

}
