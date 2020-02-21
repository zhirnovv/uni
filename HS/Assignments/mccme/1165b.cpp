#include <iostream>
using namespace std;

class HEAP {
public:
  int *h;
  int size;

  HEAP(unsigned int n) {
    size = 0;
    h = new int[n];
  }

  ~HEAP() {
    if (h)
      delete[] h;
  }

  int add(int x) {
    h[++size] = x;
    sift_up(size);
    return 1;
  }

  int extract_min(unsigned int *x) {
    if (size == 0)
      return 0;
    *x = h[1];
    h[1] = h[size--];
    sift_down(1);
    return 1;
  }

  void sift_up(int c) {
    int p;
    p = c / 2;
    if (p == 0)
      return;
    if (h[p] < h[c]) {
      int tmp;
      tmp = h[p];
      h[p] = h[c];
      h[c] = tmp;
      sift_up(p);
    }
  }

  int sift_down(int p) {
    int c;
    c = 2 * p;
    if (c > size)
      return p;
    if (c + 1 <= size && h[c + 1] > h[c])
      c++;

    if (h[c] > h[p]) {
      int tmp;
      tmp = h[c];
      h[c] = h[p];
      h[p] = tmp;
      sift_down(c);
    } else
      return p;
  }
};
int main() {
  HEAP heap(100000);
  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    int key;
    cin >> key;
    heap.add(key);
  }
  int num;
  cin >> num;
  for (int i = 0; i < num; i++) {
    int x, y;
    cin >> x >> y;
    heap.h[x] -= y;
    cout << heap.sift_down(x) << endl;
  }

  for (int i = 1; i <= heap.size; i++)
    cout << heap.h[i] << " ";

  return 0;
}
