#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;
struct node{
	int value;
	node *left;
	node *right;
};

class btree{
public:
	btree();
	~btree();

	void insert(int key);
	node *search(int key);
	void destroy_tree();
	void inorder_print();
	void postorder_print();
	void preorder_print();
    int height();
private:
	void destroy_tree(node *leaf);
	int  height(node *leaf);
	void insert(int key, node *leaf);
	node *search(int key, node *leaf);
	void inorder_print(node *leaf);
	void postorder_print(node *leaf);
	void preorder_print(node *leaf);

	node *root;
};


btree::btree(){
	root = NULL;
}

btree::~btree(){
	destroy_tree();
}

void btree::destroy_tree(node *leaf){
	if(leaf != NULL){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::insert(int key, node *leaf){
   // if ()
	if(key < leaf->value){
		if(leaf->left != NULL){
			insert(key, leaf->left);
		}else{
			leaf->left = new node;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}else if(key!= leaf->value){ if(key >= leaf->value){
		if(leaf->right != NULL){
			insert(key, leaf->right);
		}else{
			leaf->right = new node;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}}

}

void btree::insert(int key){
	if(root != NULL){
		insert(key, root);
	}else{
		root = new node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

node *btree::search(int key, node *leaf){
	if(leaf != NULL){
		if(key == leaf->value){
			return leaf;
		}
		if(key < leaf->value){
			return search(key, leaf->left);
		}else{
			return search(key, leaf->right);
		}
	}else{
		return NULL;
	}
}

node *btree::search(int key){
	return search(key, root);
}

void btree::destroy_tree(){
	destroy_tree(root);
}

void btree::inorder_print(){
	inorder_print(root);
	//cout << "\n";
}

void btree::inorder_print(node *leaf){
	if(leaf != NULL){
	    if(leaf->left == NULL ^ leaf->right == NULL)
            a.push_back(leaf->value);
		inorder_print(leaf->left);
	//	cout << leaf->value << ",";
		inorder_print(leaf->right);
	}
}


void btree::postorder_print(){
	postorder_print(root);
	cout << "\n";
}

void btree::postorder_print(node *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		inorder_print(leaf->right);
		cout << leaf->value << ",";
	}
}
int btree::height(){
	return height(root);
}
int btree::height(node *leaf) {
    if (!leaf) return 0;
    return 1 + max(height(leaf->left), height(leaf->right));
}


void btree::preorder_print(){
	preorder_print(root);
	cout << "\n";
}

void btree::preorder_print(node *leaf){
	if(leaf != NULL){
		cout << leaf->value << ",";
		inorder_print(leaf->left);
		inorder_print(leaf->right);
	}
}

int main(){

	//btree tree;
	btree *tree = new btree();
    int x;
    cin >> x;
   while(x!= 0){
        tree->insert(x);
         cin>> x;
    }
    //cout << tree->height();
    tree->inorder_print();
    sort(a.begin(), a.end());
    for(auto s : a)
        cout << s << endl;
	//tree->preorder_print();
	//tree->inorder_print();
	//tree->postorder_print();

	delete tree;

}            
