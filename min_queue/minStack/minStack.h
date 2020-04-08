#ifndef MIN_STACK
#define MIN_STACK

#include <vector>

class MinStack {
private:
  // Пара элементов: значение и минимум на момент добавления
  std::vector<std::pair<int, int> > stack;
public:
  void push(int element);
  void pop();
  int peek();
  int min();
  int size();
};

#endif
