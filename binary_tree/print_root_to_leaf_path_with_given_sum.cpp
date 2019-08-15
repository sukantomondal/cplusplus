/*Print Root to Leaf Path with Given sum*/

#include<iostream>
#include<vector>
using namespace std;

struct Node {
	int data;
	Node * left, * right;
};

Node * get_node(int data){
	Node * node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}

void print_path(Node * node, int &sum, vector<int> &path, int k){

	if(node == NULL)
		return;
	sum += node->data; 
	path.push_back(node->data);

	if(sum == k){
		for(auto x : path){
			cout << x << " ";
		}
		cout << "\n";
	}

	print_path(node->left,sum,path,k);
	print_path(node->right,sum,path,k);

	sum -= node->data;
	path.pop_back();
}


int main(){
	Node * root = get_node(1);
	root->left = get_node(2);
	root->right = get_node(3);
	root->left->left = get_node(4);
	root->left->right = get_node(5);
	root->right->left = get_node(6);
	root->right->right = get_node(7);
	root->left->left->left = get_node(8);
	root->left->left->right = get_node(9);
	root->right->left->left = get_node(10);
	root->right->left->right = get_node(11);
	root->right->right->right = get_node(12);

	int sum = 0;
	vector<int> path;
	print_path(root, sum , path , 20);

	return 0;
}
