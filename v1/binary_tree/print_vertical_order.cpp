/*Print a Binary Tree in Vertical Order | Set 2 (Map based Method)
Given a binary tree, print it vertically. The following example illustrates vertical order traversal.
           1
        /    \ 
       2      3
      / \   /   \
     4   5  6   7
               /  \ 
              8   9 
               
              
The output of print this tree vertically will be:
4
2
1 5 6
3 8
7
9

*/

#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct Node{
	int data;
	Node * left, *right;
	Node(int data) : data(data), left(NULL), right(NULL){};
};

void vertical_order(Node * node, map<int, vector<int>> &map, int hd){

	if(node == NULL)
		return;
	map[hd].push_back(node->data);
	vertical_order(node->left, map, hd-1);
	vertical_order(node->right, map, hd+1);
}

int main(){

	Node * root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->right->left = new Node(4);
	root->right->right = new Node(5);

	map<int, vector<int>> map;
	vertical_order(root, map, 0);
	for(auto x : map){
		for(auto y: x.second){
			cout << y << " ";
		}
		cout << "\n";
	}	

	return 0;
}

