#include <climits>
#include <iostream>

#include "minStack.h"

void MinStack::push(int element) {
  if (stack.empty()) {
    stack.push_back(std::make_pair(element, element));
  } else {
    int currentMinimum = stack.back().second;

    if (element < currentMinimum) {
      stack.push_back(std::make_pair(element, element));
    } else {
      stack.push_back(std::make_pair(element, currentMinimum));
    }
  }
}

void MinStack::pop() {
  if (stack.empty()) {
    return;
  } else {
    stack.pop_back();
  }
}

int MinStack::peek() { return stack.back().first; }

int MinStack::min() {
  if (stack.empty()) {
    return INT_MAX;
  } else {
    return stack.back().second;
  }
}

int MinStack::size() { return stack.size(); }
