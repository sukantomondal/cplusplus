/* Contrct binary tree from Inorder and level order*/

#include<iostream>
#include<vector>
using namespace std;


struct Node {
	int data;
	Node * left , * right;
};

Node * get_node(int data){

	Node * node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}

int search(vector<int> arr, int start, int end, int x){

	for(int i = start; i <= end ; i ++){
		if(arr[i] == x)
			return i;
	}
	return -1;
}

vector<int> extract_level_order(vector<int> levelorder, vector<int> inorder, int in_start, int in_end){
	
	vector<int> new_level;

	for(auto x : levelorder){
		for(int i = in_start ; i <= in_end; i++){
			if(inorder[i] == x ){
				new_level.push_back(x);
				break;
			}
		}
	}

	return new_level;

}

Node * build_tree(vector<int> inorder, vector<int> levelorder, int in_start, int in_end){

	
	if(levelorder.size() == 0)
		return NULL;

	int data = levelorder[0];
	Node * node = get_node(data);

	//cout << data << "\n";

	if(in_start == in_end){
		return node;
	}


	int index = search(inorder,in_start,in_end,data);

	if(index == -1)
		return NULL;

	vector<int> left_level = extract_level_order(levelorder, inorder, in_start, index-1);
	vector<int> right_level = extract_level_order(levelorder, inorder, index+1, in_end);

	node->left = build_tree(inorder, left_level, in_start,index-1);
	node->right = build_tree(inorder, right_level, index+1, in_end);

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

	vector<int> inorder = {4, 8, 10, 12, 14, 20, 22};
	vector<int> levelorder = {20, 8, 22, 4, 12, 10, 14};

	Node * root = build_tree(inorder,levelorder, 0, inorder.size()-1);

	inorder_t(root);

	return 0;
}
