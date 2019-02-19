/*Author : Sukanto Mondal */

/* 
The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes). */

#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
};

int height(Node * root){
	if(root == NULL)
		return 0;
	return 1 + max(height(root->left),height(root->right));
}


int diameter(Node * root){
	if(root==NULL)
		return 0;
	
	int lheight = height(root->left);
	int rheight = height(root->right);

	int ldiameter = diameter(root->left);
	int rdiameter = diameter(root->right);

	return max(lheight+rheight+1, max(ldiameter,rdiameter));
}

Node * new_node(int data){

	Node * temp = new Node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int main(){
	Node * root = new_node(1);
	root->left = new_node(2);
	root->right = new_node(3);
	root->left->left = new_node(4);
	root->left->right = new_node(5);
	root->left->right->left = new_node(6);
	root->left->right->right = new_node(7);
	root->right->right = new_node(8);
	root->right->right->right = new_node(9);
	root->right->right->right->left = new_node(10);
	root->right->right->right->right = new_node(11);
	root->right->right->right->left->right = new_node(12);
	cout << "The height of the tree is " << height(root) << "\n";
	cout << "The diameter of the tree is " << diameter(root) << "\n";	
	return 0;
}
