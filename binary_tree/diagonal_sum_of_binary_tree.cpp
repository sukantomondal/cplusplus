/*diagonal sum of binary tree */

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;


struct Node{
	int data;
	Node * left, * right;
};

Node * get_node(int data){

	Node * node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void diagonal(Node * root, int diagonal_no, unordered_map<int,list<Node*>> &map ){
	if(root == NULL){
		return;
	}
	map[diagonal_no].push_back(root);
	diagonal(root->left , diagonal_no+1, map);
	diagonal(root->right, diagonal_no, map);	
}

int main(){

	Node * root = get_node(1);
	root->left = get_node(2);
	root->right = get_node(3);
	root->left->left = get_node(4);
	root->left->right = get_node(5);
	root->right->left= get_node(6);

	unordered_map<int,list<Node *>> map;
	diagonal(root,0,map);

	int sum;

	for(auto x : map){
		sum = 0;
		cout << x.first << " : ";
		for(auto y : x.second){
			sum +=y->data;
			cout << y->data << " ";
		}
		cout << "SUM " << sum;
		cout << "\n";

	}
	return 0;
}
