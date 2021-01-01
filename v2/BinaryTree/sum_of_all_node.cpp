/* FInd the sum of all node in a binary tree */

#include<iostream>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

Node * get_new_node(int data) {
	Node * node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int sum (Node * node) {
	if (node == NULL)
		return 0;
	return sum(node->left) + node->data + sum(node->right);
}

int main() {
	Node * root = get_new_node(1);
	root->left = get_new_node(2);
	root->right = get_new_node(3);
	root->right->left = get_new_node(4);
	root->right->left->right = get_new_node(5);

	cout << "Sum " << sum(root) << "\n"; 
	return 0;
}
