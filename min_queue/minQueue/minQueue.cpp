#include "minQueue.h"
#include <iostream>

void MinQueue::transpose() {
  while (in.size() != 0) {
    out.push(in.peek());
    in.pop();
  }
}

void MinQueue::push(int element) { std::cout << "Pushing" << std::endl; in.push(element); }

void MinQueue::pull() { 
  if (out.size() == 0) {
    transpose();
  }
  out.pop(); 
}

int MinQueue::min() {
  if (in.size() != 0 && out.size() != 0) {
    return (in.min() > out.min()) ? out.min() : in.min();
  } else if (in.size() != 0) {
    return in.min();
  } else {
    return out.min();
  }
}
