/* Create mirror of a binanry tree */

#include<iostream>
#include<queue>
using namespace std;

struct Node {
	int data;
	Node * left;
	Node * right;
};

Node * newNode (int data) {

	Node * node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}


void print_tree(Node * node) {

	if (node == NULL)
		return;

	print_tree(node->left);
	cout << node->data << " ";
	print_tree(node->right);
}

void mirror (Node * node) {

	if (node == NULL)
		return;

	mirror(node->left);
	mirror(node->right);

	Node * left = node->left;
	Node * right = node->right;

	node->left = right;
	node->right = left;
}


void mirror_bfs(Node * node) {

	queue<Node*> nqueue;
	nqueue.push(node);

	while(!nqueue.empty()){
		Node * curr = nqueue.front();
		//cout << curr->data << " ";
		nqueue.pop();

		Node * left = curr->left;
		Node * right = curr->right;

		curr->left = right;
		curr->right = left;

		if(curr->left != NULL) { 
			nqueue.push(curr->left);
		}

		if(curr->right != NULL) {
			nqueue.push(curr->right);
		}
	}
}

int main () {

	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	print_tree(root);
	cout << "\n";

	mirror(root); 
	print_tree(root);
	cout<< "\n";

	mirror_bfs(root);
	print_tree(root);
	cout << "\n";

	return 0;
}


