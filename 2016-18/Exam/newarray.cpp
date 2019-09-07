#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

  int n, m = 0;
  cin >> n;

  std::vector<int> a(n);

  //------заполнение массива а--------

  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }

  //-----нахождение наибольшего числа элементов в массиве

  for (size_t i = 0; i < a.size(); i++) {
    int temp = 0;
    for (size_t j = 0; j < a.size(); j++) {
      if (a[j] == a[i]) {
        temp++;
      }
    }
    if (temp > m) {
      m = temp;
    }
  }

  std::vector<int> b(n);

  //------заполнение массива b и вывод

  for (size_t i = 0; i < b.size(); i++) {
    if (a[i] % 2 == 0) {
      b[i] = a[i];
    }
    else b[i] = a[i] - m;

    cout << b[i] << endl;
  }


  return 0;
}
