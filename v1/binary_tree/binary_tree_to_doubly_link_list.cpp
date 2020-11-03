/* convert a binary tree to doubly linked list*/


#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
};


Node * get_node(int data){

	Node * node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}



void convert(Node * node , Node * &pre , Node * &head){

	if(node == NULL)
		return;

	convert(node->left, pre, head);

	if(pre == NULL){
		head = node;
		pre = head;
	}else{
		pre->right = node;
		node->left = pre;
		pre = node;	
	}
	convert(node->right, pre,head);
}


void print(Node * head){
	if(head == NULL)
		return;
	cout << head->data << " ";
	print(head->right);
}


int main(){

	Node * root = get_node(1);
	root->left = get_node(2);
	root->right = get_node(3);

	root->right->right= get_node(4);

	Node * head = NULL;
	Node * pre = NULL;
	convert(root, pre,head);

	print(head);

	return 0;
}
