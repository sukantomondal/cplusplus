/*Given a Binary Tree having data at nodes as either 0’s or 1’s. The task is to find out whether there exists a subtree having an equal number of 1’s and 0’s.
 * */



#include<iostream>
#include<vector>
using namespace std;

struct Node{
	int data;
	Node * left;
	Node * right;
	Node(int data) : data(data) ,left(NULL), right(NULL) {};
};

int sum_tree(Node * node){

	if(node == NULL)
		return 0;
	int l = sum_tree(node->left); 
	int r = sum_tree(node->right);
	node->data = node->data + l + r;
	return node->data;
}

void  pre_order(Node * node, bool modify = false){

	if (node == NULL)
		return;
	if(node->data == 0 && modify)
		node->data = -1;
	else
		cout << node->data << " ";

	pre_order(node->left, modify);
	pre_order(node->right, modify);

}


bool is_equal_0_1(Node * root){

	if(root == NULL)
		return false;

	if(root->data == 0)
		return true;

	bool l = is_equal_0_1(root->left);

	if(l == true)
		return true;
	return is_equal_0_1(root->right);	
}

int main(){

	Node * root = new Node(1);

	root->right = new Node(0);
    	root->right->right = new Node(1);
    	root->right->right->right = new Node(1);
    	root->left = new Node(0);
    	root->left->left = new Node(1);
    	root->left->left->left = new Node(1);
    	root->left->right = new Node(0);
    	root->left->right->left = new Node(1);
    	root->left->right->left->left = new Node(1);
    	root->left->right->right = new Node(0);
    	root->left->right->right->left = new Node(0);
    	root->left->right->right->left->left = new Node(1);

	pre_order(root);
	cout << "\n";
	pre_order(root, true);
	pre_order(root);

	int res = sum_tree(root);
	cout << res << "\n";
	cout << "After sum tree: \n";
	pre_order(root);
	cout << "\nIs Equal 0_1 : "<< is_equal_0_1(root) << "\n";
	return 0;
}
