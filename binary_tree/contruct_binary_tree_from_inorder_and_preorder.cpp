/*contrct a binary tree from inorder and preorder */


#include<iostream>
#include<vector>
using namespace std;

struct Node{
	int data;
	Node * left, *right;
};	


Node * get_node(int data){

	Node * node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}

int search(vector<int> arr, int start, int end ,int x){

	for(int i = start ; i <= end; i++){
		if (arr[i] == x)
			return i;
	}
	return -1;
}

Node * build_tree(vector<int> inorder, vector<int> preorder, int &pre_index, int in_start, int in_end){

	int data = preorder[pre_index++];

 //	cout << data <<" " <<in_start << " " << in_end << "\n";

	Node * node = get_node(data);
	if(in_start == in_end){
		return node;
	}

	int index = search(inorder, in_start, in_end, data);

	if(index == -1)
		return NULL;

	node->left = build_tree(inorder, preorder, pre_index, in_start, index-1);
	node->right = build_tree(inorder, preorder, pre_index, index+1, in_end);

	return node;
}



void inorder_t(Node * root){

	if(root == NULL)
		return;
	inorder_t(root->left);
	cout << root->data << " ";
	inorder_t(root->right);
}
void preorder_t(Node * root){

	if(root == NULL)
		return;
	cout << root->data << " ";
	preorder_t(root->left);
	preorder_t(root->right);
}
int main(){

	vector<int> inorder = {3,2,4,1,6,5};
	vector<int> preorder = {1,2,3,4,5,6};
	int pre_index = 0;

	Node * root = build_tree(inorder,preorder,pre_index,0,inorder.size()-1);


	inorder_t(root);

	cout << "\n";

	preorder_t(root);
	cout << "\n";

	return 0;
}
