/* Find min depth of binary tree */

#include<iostream>
using namespace std;

struct Node {
	int data;
	Node * left;
	Node *right;
};

Node * newNode(int data) {
	Node * node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}



int min_depth(Node * node) {
	
	if(node == NULL)
		return 0;
	int ldepth = 1 + min_depth(node->left);
	int rdepth = 1 + min_depth(node->right);

	if(ldepth < rdepth)
		return ldepth;
	return rdepth;
}

int main () {

	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Min Depth : " << min_depth(root) << "\n";

	return 0;
}
