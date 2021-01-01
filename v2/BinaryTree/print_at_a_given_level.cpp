/*Print a binary tree at a give level */


#include<iostream>
using namespace std;

struct Node {

	int data;
	Node * left;
	Node * right;
};

Node * get_new_node (int data) {

	Node * node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void print_given_level(Node * node, int given_level, int current_level) {

	if (node == NULL)
		return;

	if(given_level == current_level) {
		cout << node->data << " ";
		return;
	}
	print_given_level(node->left, given_level, current_level+1);
	print_given_level(node->right, given_level, current_level+1);
}

int main () {

	Node * root = get_new_node(1);
	root->left = get_new_node(2);
	root->right = get_new_node(3);

	root->left->left = get_new_node(4);
	root->left->right = get_new_node(5);
	root->right->right = get_new_node(6);
	root->right->right->right = get_new_node(7);
	print_given_level(root , 3 , 1);
	return 0;
}
