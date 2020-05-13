#include "../Node/Node.h"
#include <utility>

#ifndef AVL_TREE
#define AVL_TREE

class AVLTree {
  private: 
    int nodeValue(Node* node);
    int nodeDepth(Node* node);
    int balanceFactor(Node* node);
    Node* llRotate(Node* node);
    Node* rrRotate(Node* node);
    Node* rebalance(Node* node, int value);
    std::pair<Node*, int> addNode(Node* node, int value);
    std::pair<Node*, int> deleteNode(Node* node, int value);
    bool nodeIsPresent(Node* node, int value);
  public:
    Node* root;
    AVLTree();
    int insertElement(int value);
    int deleteElement(int value);
    bool hasElement(int value);
};

#endif
