/* check a give array can be represented as pre oreder traversal of a binary tree */

#include<iostream>
#include<vector>
using namespace std;

struct Node {
	int data;
	Node * left;
	Node * right;
};

Node * newNode(int data) {
	Node * node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}

bool is_pre_order(Node * node , vector<int> & arr, int &index) {

	if(node == NULL) {
		return true;
	}

	if (node->data == arr[index]) {
		index++;
		bool lbool = is_pre_order(node->left, arr, index);
		bool rbool = is_pre_order(node->right, arr, index);
		return lbool && rbool;
	}
	else {
		return false;
	}
}

int main() {
	
	Node * root = newNode(40);
	root->left = newNode(30);
	root->right = newNode(80);
	root->left->right = newNode(35);
	root->right->right = newNode(100);

	//vector<int> arr = {40,30,35,20,80,100}; // false
	vector<int> arr = {40,30,35,80,100}; // true
	int index = 0;
	cout << "is pre order " << is_pre_order(root, arr, index);

	// Note that there coudle partially match . then we should the index goes to at the end of the array.
	return 0;
}

