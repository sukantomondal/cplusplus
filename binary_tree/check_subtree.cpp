/* Author : Sukanto Mondal */

/* Given two binary trees, check if the first tree is subtree of the second one. A subtree of a tree T is a tree S consisting of a node in T and all of its descendants in T.

The subtree corresponding to the root node is the entire tree; the subtree corresponding to any other node is called a proper subtree.
*/

#include<iostream>
#include<string.h>
using namespace std;

struct Node{
	char data;
	Node * left, *right;
};



void preorder(Node * root, char res[], int &index){
	if(root==NULL)
		return;
	res[index++] = root->data;
	preorder(root->left,res,index);
	preorder(root->right,res,index);
}

void inorder(Node * root, char res[], int &index){
	if(root==NULL){
		return;
	}
	inorder(root->left,res,index);
	res[index++] = root->data;
	inorder(root->right,res,index);
}


bool is_subtree(Node* root1, Node* root2){
	
	int m = 0, n = 0;
        char in_s[20], in_t[20];
	inorder(root1,in_s,m);
	inorder(root2,in_t,n);
	in_s[m] = '\0'; in_t[n] = '\0';

	cout << "Inorder : " << in_s << " and " << in_t <<"\n";
	if(!strstr(in_t,in_s))
		return false;

	m=n=0;
	char pre_s[20], pre_t[20];
	preorder(root1,pre_s,m);
	preorder(root2,pre_t,n);
	pre_s[m] = '\0'; pre_t[n] = '\0';

	cout <<"Preorder: " <<pre_s << " and " << pre_t << "\n" ;
	return (strstr(pre_t,pre_s) != NULL);
}


Node * new_node(char data){
	Node * temp = new Node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int main(){

	Node * root1 = new_node('x');
	root1->left = new_node('a');
	root1->right = new_node('b');
	root1->left->right = new_node('c');

	Node * root2 = new_node('z');
	root2->left = new_node('x');
	root2->right = new_node('e');
	root2->left->left = new_node('a');
	root2->left->right = new_node('b');
	root2->left->left->right = new_node('c');

	if(is_subtree(root1,root2))
		cout << "Tree1 is subtree of Tree2\n";
	else
		cout<< "Tree1 is not subtree of Tree2\n";

	return 0;
}
