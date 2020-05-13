#include "./AVLTree.h"
#include <algorithm>
#include <iostream>

int AVLTree::nodeValue(Node *node) {
  return (node == nullptr) ? 0 : node->value;
}

int AVLTree::nodeDepth(Node *node) {
  if (node == nullptr) {
    return 0;
  }

  int lDepth = (node->l == nullptr) ? 0 : node->l->depth;
  int rDepth = (node->r == nullptr) ? 0 : node->r->depth;

  return std::max(lDepth, rDepth) + 1;
}

int AVLTree::balanceFactor(Node *node) {
  return nodeDepth(node->l) - nodeDepth(node->r);
}

Node *AVLTree::llRotate(Node *node) {
  Node *r = node->r;
  Node *rl = r->l;

  r->l = node;
  node->r = rl;

  node->depth = nodeDepth(node);
  r->depth = nodeDepth(r);

  return r;
}

Node *AVLTree::rrRotate(Node *node) {
  Node *l = node->l;
  Node *lr = l->r;

  l->r = node;
  node->l = lr;

  node->depth = nodeDepth(node);
  l->depth = nodeDepth(l);

  return l;
}

Node *AVLTree::rebalance(Node *node, int value) {
  if (balanceFactor(node) > 1 && balanceFactor(node->l) >= 0) {
    std::cout << "rr" << std::endl;
    node = rrRotate(node);
  } else if (balanceFactor(node) > 1 && balanceFactor(node->l) < 0) {
    std::cout << "lr" << std::endl;
    node->l = llRotate(node->l);
    node = rrRotate(node);
  } else if (balanceFactor(node) < -1 && balanceFactor(node->r) <= 0) {
    std::cout << "ll" << std::endl;
    node = llRotate(node);
  } else if (balanceFactor(node) < -1 && balanceFactor(node->r) > 0) {
    std::cout << "rl" << std::endl;
    node->r = rrRotate(node->r);
    node = llRotate(node);
  }

  return node;
}

std::pair<Node *, int> AVLTree::addNode(Node *node, int value) {
  std::pair<Node *, int> updatedNode;

  if (node == nullptr) {
    std::cout << "new node" << std::endl;
    updatedNode.first = new Node(value);
    updatedNode.second = 0;
    return updatedNode;
  }

  if (value == node->value) {
    std::cout << "duplicate" << std::endl;
    updatedNode.first = node;
    updatedNode.second = balanceFactor(node);
    return std::make_pair(node, balanceFactor(node));
  }

  if (value < node->value) {
    std::cout << "adding on left" << std::endl;
    updatedNode = addNode(node->l, value);
    node->l = updatedNode.first;
  } else if (value > node->value) {
    std::cout << "adding on right" << std::endl;
    updatedNode = addNode(node->r, value);
    node->r = updatedNode.first;
  }

  node->depth = nodeDepth(node);
  std::cout << "nodeDepth: " << node->depth << std::endl;

  node = rebalance(node, value);

  updatedNode.first = node;
  updatedNode.second = balanceFactor(node);

  return updatedNode;
}

std::pair<Node *, int> AVLTree::deleteNode(Node *node, int value) {
  std::pair<Node *, int> updatedNode;

  if (node == nullptr) {
    std::cout << "value is not present" << std::endl;
    updatedNode.first = nullptr;
    updatedNode.second = 0;
    return updatedNode;
  }

  if (value < node->value) {
    std::cout << "going left" << std::endl;
    updatedNode = deleteNode(node->l, value);
    node->l = updatedNode.first;
  } else if (value > node->value) {
    std::cout << "going right" << std::endl;
    updatedNode = deleteNode(node->r, value);
    node->r = updatedNode.first;
  } else if (node->l == nullptr && node->r == nullptr) {
    std::cout << "no child nodes" << std::endl;
    node = nullptr;
  } else if (node->r == nullptr) {
    std::cout << "no right child nodes, replacing with first left child" << std::endl;
    node = node->l;
  } else {
    std::cout << "searching for lowest left child of a right child node"
              << std::endl;
    Node *temp = node->r;
    while (temp->l != nullptr) {
      temp = temp->l;
    }
    node->value = temp->value;
    updatedNode = deleteNode(node->r, temp->value);
    node->r = updatedNode.first;
  }

  std::cout << "checking if node is empty: ";
  if (node == nullptr) {
    std::cout << "node is empty" << std::endl;
    updatedNode.first = nullptr;
    updatedNode.second = 0;
    return updatedNode;
  }

  std::cout << "node is NOT empty" << std::endl;

  node->depth = nodeDepth(node);
  updatedNode.first = rebalance(node, value);
  updatedNode.second = balanceFactor(node);

  return updatedNode;
}

bool AVLTree::nodeIsPresent(Node *node, int value) {
  if (node == nullptr) {
    return false;
  }

  if (value < node->value) {
    return nodeIsPresent(node->l, value);
  } else if (value > node->value) {
    return nodeIsPresent(node->r, value);
  }

  return true;
}

AVLTree::AVLTree() { root = nullptr; }

int AVLTree::insertElement(int value) {
  std::pair<Node *, int> updatedTree = addNode(root, value);
  root = updatedTree.first;
  return updatedTree.second;
}

int AVLTree::deleteElement(int value) {
  std::pair<Node *, int> updatedTree = deleteNode(root, value);
  root = updatedTree.first;
  return updatedTree.second;
}

bool AVLTree::hasElement(int value) { return nodeIsPresent(root, value); }
