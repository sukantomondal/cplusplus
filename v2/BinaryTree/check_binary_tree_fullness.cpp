/* Check a binary tree is full or not */

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


bool check_full (Node * node) {

	if (node == NULL)
		return true;
	if(node->left == NULL && node->right != NULL)
		return false;
	if(node->right == NULL && node->left != NULL)
		return false;
	return check_full(node->left) && check_full(node->right);
}

int main() {

	Node * root = newNode(1);	
	root->left = newNode(20);
    	root->right = newNode(30);

    	root->left->right = newNode(40);
    	root->left->left = newNode(50);
    	root->right->left = newNode(60);
    	root->right->right = newNode(70);

    	root->left->left->left = newNode(80);
    	root->left->left->right = newNode(90);
    	root->left->right->left = newNode(80);
    	root->left->right->right = newNode(90);
    	root->right->left->left = newNode(80);
    	root->right->left->right = newNode(90);
    	//root->right->right->left = newNode(80);
    	root->right->right->right = newNode(90);
	
	cout << "IS FULL " << check_full(root) << "\n"; 

	return 0;
}
