/*Construct a Binary Tree from Postorder and Inorder */

#include<iostream>
#include<vector>
using namespace std;

struct Node {

	int data;
	Node * left, * right;
};

Node * get_node(int data){

	Node *node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}


int search(vector<int> arr, int start, int end , int x){

	for(int i = start; i <= end; i++){

		if(arr[i] == x)
			return i;
	}
	return -1;
}

Node * build_tree(vector<int> inorder, vector<int> postorder, int &post_index, int in_start, int in_end){

	if(post_index < 0)
		return NULL;

	int data = postorder[post_index--];
	Node * node  = get_node(data);

	if(in_start == in_end)
		return node;

	int index = search(inorder, in_start, in_end, data);

	node->right = build_tree(inorder, postorder, post_index,index+1,in_end);
	node->left = build_tree(inorder, postorder, post_index, in_start, index-1);
	return node;
}


void inorder_t(Node * root){

	if(root == NULL)
		return;

	inorder_t(root->left);
	cout << root->data << " ";
	inorder_t(root->right);
}

int main(){

	vector<int> inorder = {4, 8, 2, 5, 1, 6, 3, 7};
	vector<int> postorder = {8, 4, 5, 2, 6, 7, 3, 1};
	int post_index = postorder.size()-1;
	
	Node * root = build_tree(inorder, postorder, post_index, 0, inorder.size()-1);

	inorder_t(root);

	cout << "\n";

	return 0;
}
