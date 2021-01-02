/* bottom view of a binary tree */

#include<iostream>
#include<unordered_map>
#include<utility>
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
	return node;
}

void bottom_view(Node * node,int hd, int height, unordered_map<int, pair<int, int>> &map) {

	if(node == NULL) {
		return;
	}

	if(map.find(hd) == map.end()){
		map[hd] = make_pair(height, node->data);

		if (hd==1)
			cout << "orginal : " <<node->data << "\n";
	}
	else {

		if (hd == 1) {
			cout << "replace : " << node->data << "\n";
		}
		pair<int,int> p = map[hd];
		if (p.first < height)
			map[hd] = make_pair(height, node->data);
	}

	cout << node->data << "\n";

	bottom_view(node->left, hd-1, height+1, map);
	bottom_view(node->right, hd+1, height+1, map);
}


int main() {
	
	Node * root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(5);
	root->left->right = newNode(3);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	root->right->right = newNode(25);

	unordered_map<int, pair<int, int>> map;
	bottom_view(root, 0, 0, map);
	cout << "Bottom view is ";
	for(auto &it : map) {
		cout << it.second.second << " ";
	}
	cout << "\n";
	return 0;
}
