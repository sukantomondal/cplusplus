/* Max path sum in a binary tree */

#include<iostream>
#include<algorithm>
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
}


int max_path_sum(Node *node, int &_max) {

	if (node == NULL) {
		return 0;
	}

	int lsum = max_path_sum(node->left,_max);
	int rsum = max_path_sum(node->right,_max);

	int max_child_sum = max(lsum, rsum) + node->data;
	_max = max(max (max_child_sum, lsum+rsum+node->data), _max);
	cout << "data " << node->data << " max " << _max << "\n";

	return max(max_child_sum, node->data); 
}

int main () {

	Node * root = newNode(10);
	root->left = newNode(2);
	root->right = newNode(10);
	root->left->left = newNode(20);
	root->left->right = newNode(1);
	root->right->right = newNode(-25);
	root->right->right->left = newNode(3);
	root->right->right->right = newNode(4);
	int _max;
	max_path_sum(root,_max);
	cout << "Max path sum : " << _max << "\n"; 
	return 0;
}
