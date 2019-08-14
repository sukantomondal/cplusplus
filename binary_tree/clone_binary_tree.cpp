/*Clone a Binary Tree with Random Pointers
Given a Binary Tree where every node has following structure.

struct node {  
    int key; 
    struct node *left,*right,*random;
} 
The random pointer points to any random node of the binary tree and can even point to NULL, clone the given binary tree.

*/

#include<iostream>
#include<unordered_map>
using namespace std;

struct Node{
	int data;
	Node * left, *right, *random;
};

Node * get_node(int data){

	Node * node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->random = NULL;
	return node;
}

void print_inorder(Node * root){
	if(root == NULL){
		return;
	}
	print_inorder(root->left);
	cout <<"{" <<root->data << " ";
	if(root->random){
		cout<< root->random->data;
	}
	else{
		cout << "NULL";
	}
	cout << "} ";
	print_inorder(root->right);

}


Node * clone_tree(Node * root, unordered_map<Node*, Node*> &map){

	if(root == NULL){
		return NULL;
	}

	Node * clone_node = get_node(root->data);
	map[root] = clone_node;
	clone_node->left = clone_tree(root->left, map);
	clone_node->right = clone_tree(root->right, map);
	return clone_node;
}


void add_random(Node * root, Node * clone_root, unordered_map<Node *, Node*> &map){

	if(root == NULL)
		return;
	clone_root->random = map[root->random];
       	add_random(root->left,clone_root->left,map);
	add_random(root->right,clone_root->right,map);	
}

int main(){

	Node * root = get_node(1);
	root->left = get_node(2);
	root->right = get_node(3);
	root->left->left = get_node(4);
	root->left->right = get_node(5);

	root->left->left->random = root;
	root->random = root->left->right;
	root->left->right->random = root->left;

	print_inorder(root);
	cout << "\n";

	unordered_map<Node*, Node*> map;
	Node * clone_root = clone_tree(root,map);
	add_random(root,clone_root,map);

	print_inorder(clone_root);
	cout << "\n";

	return 0;
}
