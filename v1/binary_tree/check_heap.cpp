/*Check if a given Binary Tree is Heap
Given a binary tree, we need to check it has heap property or not, Binary tree need to fulfill the following two conditions for being a heap –

It should be a complete tree (i.e. all levels except last should be full).
Every node’s value should be greater than or equal to its child node (considering max-heap).

*/

#include<iostream>
#include<vector>
using namespace std;

struct Node{
	int val;
	Node * left, *right;
};


Node *get_new_node(int val){
	Node *node = new Node();
	node->val = val;
	node->left = node->right =NULL;
	return node;
}



int count_nodes(Node * root){

	if(root == NULL)
		return 0;
	return 1 + count_nodes(root->left) + count_nodes(root->right);
		
}

bool is_complete(Node *root, int index , int no_of_nodes){   // is binary tree is complete

	if(root == NULL)
		return true;

	 // If index assigned to current node is more than
    	// number of nodes in tree, then tree is not complete
	if(index >= no_of_nodes){
		return false;
	}

	return (is_complete(root->left, 2*index+1, no_of_nodes) && is_complete(root->right, 2*index+2, no_of_nodes));
}

bool is_heap(Node *root){

	if(root->left ==NULL && root->right == NULL ){
		return true;
	}
	if(root->right == NULL){
		// because no need to check  right side any more
		return (root->val >= root->left->val);
	}
	else{
		if((root->val >= root->left->val) && (root->val >= root->right->val))
		       	return (is_heap(root->left) && is_heap(root->right));
		else
			return false;
	}
	
}

int main(){

	Node * root = get_new_node(97);
	root->left = get_new_node(46);
	root->right = get_new_node(37);
	root->left->left = get_new_node(12);
	root->left->right = get_new_node(3);
	root->left->left->left = get_new_node(6);
	root->left->left->right = get_new_node(9);
	root->right->left = get_new_node(7);
	root->right->right = get_new_node(31);


	int no_of_nodes = count_nodes(root);

	cout << "Is Complete  : " << is_complete(root, 0, no_of_nodes) << "\n";

	cout << "Is heap: " << is_heap(root) << "\n";

	cout << "Number of nodes in the tree is : " << count_nodes(root) << "\n";

	return 0;
}
