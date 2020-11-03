/* Author : Sukanto Mondal */


/*
Check whether a binary tree is a full binary tree or not

A full binary tree is defined as a binary tree in which all nodes have either zero or two child nodes. Conversely, there is no node in a full binary tree, which has one child node.
*/

#include <iostream>
using namespace std;

struct Node {

	int data;
	Node * lchild , * rchild;
};


bool check_is_full_tree(Node * root){

	if(root==NULL)
		return true;
	if(root->lchild == NULL && root->rchild == NULL)
		return true;

	if((root->lchild != NULL && root->rchild != NULL))
		return (check_is_full_tree(root->lchild) && check_is_full_tree(root->rchild));
	else
		return false;
}

Node *new_node(int data){

	Node *temp = new Node();
	temp->data = data; 
	temp->lchild = NULL;
	temp->rchild = NULL;
	return temp;

}

int main(){
	
	Node * root = new_node(1);
	root->lchild = new_node(2);
	root->rchild = new_node(3);
	root->lchild->lchild = new_node(4);
	root->lchild->rchild = new_node(5);

	if(check_is_full_tree(root))
		cout<< "The tree is FULL. \n";
	else
		cout << "The tree is not FULL. \n";

	return 0;
}
