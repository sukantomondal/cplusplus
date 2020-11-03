/*Print cousins of a given node in Binary Tree
Given a binary tree and a node, print all cousins of given node. Note that siblings should not be printed.

Example:

Input : root of below tree 
             1
           /   \
          2     3
        /   \  /  \
       4    5  6   7
       and pointer to a node say 5.

Output : 6, 7
*/

#include<iostream>
using namespace std;


struct Node {

	int data;
	Node * left;
	Node * right;
};


Node * get_new_node(int data){

	Node * node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}

int get_level(Node * root, Node * node , int level){

	if(root == NULL)
		return 0;

	if(root == node)
		return level;

	int l = get_level(root->left, node, level+1);
	if (l!=0) return l;

	return get_level(root->right,node, level+1);	
}

void  print_level(Node * root, Node * node, int level) {

	if(root==NULL){
		return ;
	}

	if(level == 0){
		if(!(root->left == node || root->right == node)){
			if(root->left != NULL) cout << root->left->data << " ";
			if(root->right != NULL) cout << root->right->data << " ";
		}
	}
	else{
		print_level(root->left, node, level-1);
		print_level(root->right, node, level-1);
	}
}


void print_sibling(Node *root, Node * node){

	int level = get_level(root, root->right->left, 0);
	print_level(root,node, level-1);
	cout << "\n";

}

int main(){

	Node * root = get_new_node(1);
	
	root->left = get_new_node(2);
	root->right = get_new_node(3);
	root->left->left = get_new_node(4);
	root->left->right = get_new_node(5);
	root->right->left = get_new_node(6);
	root->right->right = get_new_node(7);

	print_sibling(root, root->right->left);

	return 0;
}
