/* Reverse the linked list */


#include<iostream>
using namespace std;


struct Node{
	int val;
	Node * next;
};

Node * get_new_node(int val){

	Node *node = new Node();
	node->val = val;
	node->next = NULL;
	return node;
}

void print(Node *root){

	while(root!=NULL){
		cout << root->val << " ";
		root = root->next;
	}
	cout << "\n";
}


void reverse(Node *root){

	Node * curr = root;
	Node *next = NULL;
	Node *pre = NULL;

	while(curr!=NULL){
		next = curr->next;
		curr->next = pre;
		pre = curr;
		curr = next;
	}

	root = pre;
	print(root);
}

Node* insert(Node * node, int val){

        Node * new_node = get_new_node(val);
        new_node->next = node;
        return new_node;
}

void reverse_using_recursion (Node *root , Node *&result){
	if(root==NULL){
                return;
        }
        result = insert(result,root->val);
        reverse_using_recursion(root->next,result);
}

int main(){


	Node *root = get_new_node(0);
	root->next = get_new_node(1);
	root->next->next = get_new_node(2);
	root->next->next->next = get_new_node(3);

	print(root);
	//reverse(root);

	cout << "Using recursion method \n";
	Node * result = NULL;
	reverse_using_recursion(root,result);
	print(result);


	cout << "Using itertive method \n";
	reverse(root);

	return 0;
}
