#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct data {
  int id;
  int arg1;
  int arg2;
};

void move(vector<data> &v, int arg1, int arg2) {
  for (int i = 0; i < (arg1 * arg2) % 11; i++) {
    for (int i = 10; i >= 1; i--) {
      swap(v[i], v[i - 1]);
    }
  }

  cout << v[0].id << endl;

  if (v[0].id == 1)
    return;
  else
    move(v, v[0].arg1, v[0].arg2);
}

int main(int argc, char const *argv[]) {
  vector<data> v(11);

  for (size_t i = 0; i < 11; i++) {
    v[i].id = i + 1;
  }

  v[0].arg1 = 3; v[0].arg2 = 6311;
  v[1].arg1 = 2; v[1].arg2 = 554;
  v[2].arg1 = 4; v[2].arg2 = 1247;
  v[3].arg1 = 9; v[3].arg2 = 803;
  v[4].arg1 = 8; v[4].arg2 = 193;
  v[5].arg1 = 5; v[5].arg2 = 12;
  v[6].arg1 = 6; v[6].arg2 = 14;
  v[7].arg1 = 7; v[7].arg2 = 8;
  v[8].arg1 = 10; v[8].arg2 = 4967;
  v[9].arg1 = 7; v[9].arg2 = 35;
  v[10].arg1 = 3; v[10].arg2 = 25;

  move(v, v[0].arg1, v[0].arg2);

  return 0;
}
