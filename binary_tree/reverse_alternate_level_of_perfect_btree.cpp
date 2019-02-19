/*Author : Sukanto Mondal */

/*Given a Perfect Binary Tree, reverse the alternate level nodes of the binary tree. */
/*
Given tree: 
               a
            /     \
           b       c
         /  \     /  \
        d    e    f    g
       / \  / \  / \  / \
       h  i j  k l  m  n  o 

Modified tree:
             a
            /     \
           c       b
         /  \     /  \
        d    e    f    g
       / \  / \  / \  / \
      o  n m  l k  j  i  h       
*/

#include <iostream>
using namespace std;

struct Node {

	char data;
	Node *left, *right;
};

int height(Node * root){

	if(root == NULL)
		return 0;
	return 1 + max(height(root->left), height(root->right));
}

void reverse(char res[], int l, int r){

	if(l==r)
		return;

	while (l<r){
		char t = res[l];
		res[l++] = res[r];
		res[r--] = t;
	}
}

void get_level_nodes(Node* root,int level,char res[], int &index){

	if(root==NULL)
		return;
	if(level == 1){
		res[index++] = root->data;
	}
	else if(level>1){
		get_level_nodes(root->left,level-1,res,index);
		get_level_nodes(root->right,level-1,res,index);
	}
}

void reverse_level_node(Node *root, int level, char res[], int& index){

	if(root==NULL)
	       	return;
        if(level == 1){
		root->data = res[index++];

        }
        else if(level>1){
	       	reverse_level_node(root->left,level-1,res,index);
	       	reverse_level_node(root->right,level-1,res,index);
        }
}

void reverse_alternate_level(Node * root){

	int h = height(root);
	for (int i = 1 ; i<=h; i++){

		if(i%2 == 0){

			char n_l[20];
			int m =0;
			get_level_nodes(root,i,n_l,m);
			n_l[m] = '\0';

			reverse(n_l,0,m-1);
			m = 0;
			reverse_level_node(root,i,n_l,m);
		}
	}	
}


void print_level_order(Node *root){

	int h = height(root);
	for(int i = 1; i <= h ; i++){
	
		char n_l[20];
		int m = 0;
		get_level_nodes(root,i,n_l,m);
		n_l[m] = '\0';
		cout << n_l << "\n";
	}
}

Node * new_node(char data){
	Node * temp = new Node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int main(){

	Node * root = new_node('a');
	root->left = new_node('b');
	root->right = new_node('c');

	cout << "Before alternation : \n";
	print_level_order(root);	
	reverse_alternate_level(root);
	cout << "After Alternation :  \n";
	print_level_order(root);
	return 0;
}
