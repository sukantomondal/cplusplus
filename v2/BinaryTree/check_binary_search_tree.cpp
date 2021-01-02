/* check a tree is binary serach tree is not */

#include<iostream>
using namespace std;

struct Node {
	int data;
	Node * left;
	Node * right;
};

Node * newNode (int data) {
	Node * node = new Node();
	node->data= data;
	node->left = NULL;
	node->right = NULL;
}

bool is_binary_search_tree(Node * node, int _min, int _max ) {
	
	if(node == NULL)
		return true;

	if(node->data < _min || node->data > _max ) {
		return false;
	}

	bool lbool = is_binary_search_tree(node->left, _min, node->data-1);
	bool rbool = is_binary_search_tree(node->right, node->data+1, _max);

	return lbool && rbool;
}



int main() {

	Node * root = newNode(100);
	root->left = newNode(95);
	root->right = newNode(105);
	root->left->left = newNode(65);
	root->left->right = newNode(97);
	root->left->right->left = newNode(96);
	root->left->right->right = newNode(99);
	cout <<"Is BST " << is_binary_search_tree(root, INT8_MIN, INT8_MAX) << "\n";
	return 0;
}
