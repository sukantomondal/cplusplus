/*Check if a given Binary Tree is SumTree
Write a function that returns true if the given Binary Tree is SumTree else false. A SumTree is a Binary Tree where the value of a node is equal to sum of the nodes present in its left subtree and right subtree. An empty tree is SumTree and sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.

Following is an example of SumTree.


  	 26
        /   \
      10     3
    /    \     \
  4      6      3

  https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-sumtree/

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


int sum (Node *root){

	if(root == NULL )
		return 0;
	return sum(root->left) + root->data + sum(root->right);
}

bool is_leaf(Node * root){

	if(root == NULL)
		return 0;
	if(root->left == NULL && root->right ==NULL){
		return 1;
	}
	return 0;
}

bool is_sum_tree(Node * root){  // O(n)

	if(root==NULL || is_leaf(root)){
		return true;
	}

        if (is_sum_tree(root->left) && is_sum_tree(root->right)){

		int ls =0;
		if(root->left == NULL){
			ls = 0;
		}else if(is_leaf(root->left)){
			ls = root->left->data;
		}else{
			ls = 2*root->left->data;
		}

		int rs = 0;

		if(root->right == NULL){
			rs = 0;
		}
		else if(is_leaf(root->right)){
			rs = root->right->data;
		}else{
			rs = 2*root->right->data;
		}

		cout << root->data << " " << ls +rs << "\n";

		return (root->data == ls + rs);
	}

	return false;
}


bool is_sum_tree_alt(Node * root){ // O(n^2) solution

	if(root == NULL || is_leaf(root))
		return true;

	int ls = sum(root->left);
	int rs = sum(root->right);

	return (root->data == ls+rs && is_sum_tree_alt(root->left) && is_sum_tree(root->right));
}


int main(){

	Node * root = get_new_node(26);
	root->left = get_new_node(10);
	root->right = get_new_node(3);
	root->left->left = get_new_node(4);
	root->left->right = get_new_node(6);
	root->right->right = get_new_node(3);


	cout <<" Is sum tree(O(n)) :" <<is_sum_tree(root) << "\n";

	cout << "Is sum tree alt (O(n^2)) : " << is_sum_tree_alt(root->left) << "\n";

	return 0;
}


