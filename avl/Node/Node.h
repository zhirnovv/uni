#ifndef NODE
#define NODE

class Node {
  public:
    int value;
    Node* l;
    Node* r;
    int depth;

    Node(int initValue);
};

#endif
