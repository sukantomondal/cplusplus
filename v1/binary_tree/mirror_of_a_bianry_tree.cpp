/* mirron of a binary tree */

#include<iostream>
using namespace std;


struct Node {
	int data;
	Node * left , * right;
};

Node * get_node(int data){

	Node * node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}

void mirror(Node * node){
	if(node == NULL)
		return;

	mirror(node->left);
	mirror(node->right);

	Node * tmp = node->left;
	node->left = node->right;
	node->right = tmp;
}


void inorder(Node * root){

	if(root == NULL)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}


int main(){

	Node * root = get_node(1);
	root->left = get_node(2);
	root->right = get_node(3);
	root->left->left = get_node(4);
	root->right->right = get_node(5);

	inorder(root);
	cout << "\n";
	mirror(root);

	inorder(root);
	cout << "\n";

	return 0;
}
