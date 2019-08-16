/*Check a binary tree is complete or not*/
/*
A Full Binary Tree is a binary tree where every node has either 0 or 2 children

Following are examples of Full Trees.
1
      /   \
    2       3
  /  \     /  \
 4    5   6    7


       1
     /   \
   2      3
        /   \  
       4     5
           /   \  
          6    7
                  

          1
        /   \
      2       3
    /  \     /  \
   4    5   6    7
 /  \  
8    9 

*/


#include<iostream>
using namespace std;

struct Node {
	int data;
	Node * left, *right;
};

Node * get_node(int data){

	Node * node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}


bool is_full(Node * root){

	if(root->left == NULL && root->right == NULL)
		return true;

	if (root->left && root->right && is_full(root->left) && is_full(root->right)){
		return true;			
	}
	return false;
}

int main(){


	Node * root = get_node(1);
	root->left = get_node(2);
	root->right = get_node(3);
	root->right->left = get_node(4);
	root->right->right = get_node(5);
	root->right->right->left = get_node(6);
	root->right->right->right = get_node(7);


	cout << is_full(root);

	return 0;
}
