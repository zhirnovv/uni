#include <iostream>

using namespace std;

class BST {
  struct node {
    int data;
    node *left;
    node *right;
  };

  node *root;

  node *makeEmpty(node *t) {
    if (t == NULL)
      return NULL;
    {
      makeEmpty(t->left);
      makeEmpty(t->right);
      delete t;
    }
    return NULL;
  }

  node *insert(int x, node *t) {
    if (t == NULL) {
      t = new node;
      t->data = x;
      t->left = t->right = NULL;
    } else if (x < t->data)
      t->left = insert(x, t->left);
    else if (x > t->data)
      t->right = insert(x, t->right);
    return t;
  }

  node *findMin(node *t) {
    if (t == NULL)
      return NULL;
    else if (t->left == NULL)
      return t;
    else
      return findMin(t->left);
  }

  node *findMax(node *t) {
    if (t == NULL)
      return NULL;
    else if (t->right == NULL)
      return t;
    else
      return findMax(t->right);
  }

  node *findSecondMax(node *t) {
    node *z = new node;
    if(t->right == NULL && t->left != NULL)
    {
      z = t->left;
      if(z->right != NULL)
       return findSecondMax(z);
      else return z;
    }
    else if(t->right != NULL)
    {
      z = t->right;
      if(z->right == NULL && z->left == NULL)
        return t;
      else return findSecondMax(z);
    }
  }

  node *remove(int x, node *t) {
    node *temp;
    if (t == NULL)
      return NULL;
    else if (x < t->data)
      t->left = remove(x, t->left);
    else if (x > t->data)
      t->right = remove(x, t->right);
    else if (t->left && t->right) {
      temp = findMin(t->right);
      t->data = temp->data;
      t->right = remove(t->data, t->right);
    } else {
      temp = t;
      if (t->left == NULL)
        t = t->right;
      else if (t->right == NULL)
        t = t->left;
      delete temp;
    }

    return t;
  }

  void inorder(node *t) {
    if (t == NULL)
      return;
    inorder(t->left);
    cout << t->data << " ";
    inorder(t->right);
  }

  node *find(node *t, int x) {
    if (t == NULL)
      return NULL;
    else if (x < t->data)
      return find(t->left, x);
    else if (x > t->data)
      return find(t->right, x);
    else
      return t;
  }

public:
  BST() { root = NULL; }

  ~BST() { root = makeEmpty(root); }

  void insert(int x) { root = insert(x, root); }

  void remove(int x) { root = remove(x, root); }

  void findSecondMax() {root = findSecondMax(root);}

  void display() {
    cout << root->data;
    cout << endl;
  }

  void search(int x) { root = find(root, x); }
};

int main() {
  BST t;
  int input;
  cin >> input;
  while(input)
  {
    t.insert(input);
    cin >> input;
  }

  t.findSecondMax();
  t.display();
  return 0;
}
