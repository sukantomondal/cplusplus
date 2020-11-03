/*Sum of all the Boundary Nodes of a Binary Tree
Given a binary tree, the task is to print the sum of all the boundary nodes of the tree.

Input:
               1
             /   \
            2     3
           / \   / \
          4   5 6   7
Output: 28

Input:
                1
              /   \
             2     3
              \    /
               4  5
                  \
                   6
                  / \
                 7   8
Output: 36
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

void left_nodes(Node * root, int &left_sum){

	if(root == NULL)
		return;
	if(root->left == NULL && root->right == NULL)
		return;

	if(root->left){
		left_sum += root->data;
		left_nodes(root->left,left_sum);
	}else if(root->right){
		left_sum += root->data;
		left_nodes(root->right,left_sum);
	}	
}


void right_nodes(Node *root, int &right_sum){

	if(root==NULL)
		return;
	if(root->left == NULL && root->right == NULL)
		return;

	if(root->right){
		right_sum += root->data;
		right_nodes(root->right,right_sum);
	}else if(root->left){
		right_sum += root->data;
		right_nodes(root->left,right_sum);
	}

}

void leves_nodes(Node * root, int &leves_sum){

	if(root == NULL)
		return;

	if(root->left == NULL && root->right == NULL){
		leves_sum +=root->data;
	}

	leves_nodes(root->left,leves_sum);
	leves_nodes(root->right,leves_sum);
}

int sum_boundary_nodes(Node * root){

	int left_sum = 0, right_sum = 0, leves_sum = 0;

	if(root!= NULL){
		left_nodes(root->left,left_sum);
		right_nodes(root->right,right_sum);
		leves_nodes(root,leves_sum);
	}

	return root->data + left_sum + right_sum + leves_sum;
}

int main(){

	Node * root = get_new_node(1);
	root->left = get_new_node(2);
	root->right =get_new_node(3);
	root->left->right = get_new_node(4);
	root->right->left = get_new_node(5);
	root->right->left->right = get_new_node(6);
	root->right->left->right->left = get_new_node(7);
	root->right->left->right->right = get_new_node(8);

	int sum = sum_boundary_nodes(root);
	cout <<"Boundary Sum : "<< sum  <<"\n";

	return 0;
}
