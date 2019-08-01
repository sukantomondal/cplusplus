/*Check if two nodes are cousins in a Binary Tree
Given the binary Tree and the two nodes say ‘a’ and ‘b’, determine whether the two nodes are cousins of each other or not.
Two nodes are cousins of each other if they are at same level and have different parents.

Example:

     6
   /   \
  3     5
 / \   / \
7   8 1   3
Say two node be 7 and 1, result is TRUE.
Say two nodes are 3 and 5, result is FALSE.
Say two nodes are 7 and 5, result is FALSE.

*/
#include<iostream>
using namespace std;

struct Node {

	int data;
	Node * left;
	Node * right;
};


Node * get_new_node(int data){

	Node * node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}


void get_level(Node * root, Node * search_node ,int level, int &res_level){

	if(root==NULL)
		return;
	if(root== search_node)
		res_level = level;

	get_level(root->left,search_node ,level+1,res_level);
	get_level(root->right, search_node, level+1, res_level);
}


bool is_sibling(Node *root, Node *node1, Node *node2, bool &sibling){

	if(root==NULL)
		return false;

	if((root->left == node1 && root->right == node2) || (root->left == node2 && root->right == node1)){
		sibling = true;
		return true;
	}

	is_sibling(root->left, node1 ,node2, sibling);
	is_sibling(root->right, node1, node2, sibling);
}

bool is_cousin(Node *root, Node * node1, Node * node2){

	if(root == NULL)
		return false;

	int level1 =0, level2 =0;
	get_level(root,node1,0,level1);
	get_level(root,node2,0,level2);
	bool sibling;
	is_sibling(root,node1,node2,sibling);
	if(level1 == level2 && !sibling)
		return true;

	return false;
}

int main(){

	Node * root = get_new_node(6);
	root->left = get_new_node (3);
	root->right = get_new_node(5);
	root->left->left = get_new_node(7);
	root->left->right = get_new_node(8);
	root->right->left = get_new_node(1);
	root->right->right = get_new_node(3);

	Node * node1 = root->right->left;
	Node * node2 = root->left->right;
	
	cout<<  node1->data << " and  " << node2->data << " is cousin : " <<is_cousin(root,node1,node2) << "\n";

	return 0;
}
