/*Subtree with given sum in a Binary Tree
You are given a binary tree and a given sum. The task is to check if there exist a subtree whose sum of all nodes is equal to the given sum.

*/

#include<iostream>
#include<vector>
using namespace std;

struct Node{

	int data;
	Node * left;
	Node * right;
	Node(int data) : data(data), left(NULL), right(NULL) {};
};

pair<bool, int> sub_tree_with_given_sum(Node * node, int sum){

	if(node == NULL)
		return {false,0};

	pair<bool, int> l = sub_tree_with_given_sum(node->left, sum);
	pair<bool, int> r = sub_tree_with_given_sum(node->right, sum);

	if(l.first || r.first || node->data + l.second + r.second == sum){
		return {true, node->data+ l.second + r.second};
	}else{

		return {false, node->data + l.second + r.second};
	}
}

int main(){


	struct Node *root = new Node(8); 
    	root->left    = new Node(5); 
    	root->right   = new Node(4); 
    	root->left->left = new Node(9); 
    	root->left->right = new Node(7); 
    	root->left->right->left = new Node(1); 
    	root->left->right->right = new Node(12); 
    	root->left->right->right->right = new Node(2); 
    	root->right->right = new Node(11); 
    	root->right->right->left = new Node(3); 
    	int sum = 15; 


	pair<bool, int> res =  sub_tree_with_given_sum(root, sum);

	if(res.first)
		cout << "True \n";
	else{
		cout << "False \n";
	}

	return 0;
}
