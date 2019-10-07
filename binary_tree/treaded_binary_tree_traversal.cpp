/*Inorder Tree Traversal without recursion and without stack!
Using Morris Traversal, we can traverse the tree without using stack and recursion. The idea of Morris Traversal is based on Threaded Binary Tree. In this traversal, we first create links to Inorder successor and print the data using these links, and finally revert the changes to restore original tree.

1. Initialize current as root 
2. While current is not NULL
   If the current does not have left child
      a) Print current’s data
      b) Go to the right, i.e., current = current->right
   Else
      a) Make current as the right child of the rightmost 
         node in current's left subtree
      b) Go to this left child, i.e., current = current->left
*/

#include<iostream>
#include<vector>
using namespace std;

struct Node{

	int data;
	Node * left;
	Node * right;
};

Node * get_node(int data){

	Node * node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}


void morrison_traversal(Node * root, vector<int> &res){

	Node * curr = root;


	while(curr != NULL){

		if(curr->left == NULL){
			res.push_back(curr->data);
			curr = curr->right;
		}else{

		Node * pre = curr->left;

		while(pre->right != NULL && pre->right != curr){
			pre = pre->right;
		}

		if(pre->right == NULL){
			pre->right = curr; // thread;
			curr = curr->left;
		}
		else{
			pre->right = NULL; // restore the tree connection.
			res.push_back(curr->data);
			curr = curr->right;
		}
		}

	}

}

int main(){

	Node * root = get_node(1);
	root->left = get_node(2);
	root->right = get_node(3);
	root->right->left = get_node(4);
	root->right->right = get_node(5);

	vector<int> res;
	morrison_traversal(root,res);

	for(auto x : res){
		cout << x << " ";
	}

	cout << "\n";

	return 0;
}
