/* lowest common ancestor of a binary search tree */

#include<iostream>
using namespace std;

struct Node {
	int data;
	Node * left;
	Node * right;
};

Node * newNode(int data) {
	Node * node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}


int common_ancestor(Node * node, int num1, int num2) {

	if(node == NULL) {
		return -1;
	}

	if(node->data > num1 && node->data > num2) {
		return common_ancestor(node->left, num1, num2);
	} else if (node->data < num1 && node->data < num2) {
		return common_ancestor(node->right, num1, num2);
	} else {
		return node->data;
	}
}

int main() {

	Node * root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	cout << common_ancestor(root, 10, 14);
	return 0;
}
