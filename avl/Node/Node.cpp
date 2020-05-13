#include "Node.h"

Node::Node(int initValue) {
  value = initValue;
  l = nullptr;
  r = nullptr;
  depth = 1;
}
