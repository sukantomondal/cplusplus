/*Replace every element with the least greater element on its right
Given an array of integers, replace every element with the least greater element on its right side in the array. If there are no greater element on right side, replace it with -1.

Examples:

Input: [8, 58, 71, 18, 31, 32, 63, 92, 
         43, 3, 91, 93, 25, 80, 28]
Output: [18, 63, 80, 25, 32, 43, 80, 93, 
         80, 25, 93, -1, 28, -1, -1]

*/


#include<iostream>
#include<vector>
using namespace std;

struct Node{
	int data;
	Node * left;
	Node *right;

	Node (int data) : data(data), left(NULL), right(NULL) {};
};


Node * binary_search_insert(Node * node, int data, Node * &succ){


	if(node == NULL){
		return new Node(data);
	}

	if(node->data >= data){
		succ= node;
		node->left = binary_search_insert(node->left, data, succ);
	}else{
		node->right = binary_search_insert(node->right, data,succ);
	}

	return node;
}

void inorder(Node * node){

	if(node == NULL)
		return;

	inorder(node->left);
	cout << node->data << " ";
	inorder(node->right);
}

void replace(vector<int> &arr){

	Node * root = NULL;
	Node * succ = NULL;

	for(int i = arr.size()-1; i >= 0; i--){

		succ = NULL;
		root = binary_search_insert(root,arr[i],succ);

		if(succ == NULL){
			arr[i] = -1;
		}else{
			arr[i] = succ->data;
		}
	}

	//inorder(root);
}



void print_array(vector<int> arr){

	for(auto x : arr){
		cout << x << " ";
	}
	cout << "\n";

}

int main(){

	vector<int> arr = {8,58,71,18,31,32,63,92,43,3,91,93,25,80,28};

	print_array(arr);
	replace(arr);
	print_array(arr);

	return 0;
}
