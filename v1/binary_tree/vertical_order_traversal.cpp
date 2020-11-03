/*vertical order traversal */
#include<iostream>
#include<queue>
#include<map>
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

void vertical_order_travarsal(Node * root, int hd, map<int, vector<int>> &map){

	if(root == NULL){
		return;
	}

	map[hd].push_back(root->data);
	vertical_order_travarsal(root->left,hd-1,map);
	vertical_order_travarsal(root->right,hd+1,map);
}

int main(){
	
	Node * root = get_node(1);
	root->left = get_node(2);
	root->right = get_node(3);
	root->left->left = get_node(4);
	root->left->right = get_node(5);
	root->right->left = get_node(6);
	root->right->right = get_node(7);

	map<int,vector<int>> map;
	vertical_order_travarsal(root,0, map);

	for(auto x : map){
		cout << x.first << ": ";

		for(auto y : x.second){
			cout << y << " ";
		}

		cout << "\n";
	}

	return 0;
}
