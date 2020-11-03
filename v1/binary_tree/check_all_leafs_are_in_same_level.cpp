/*Check if all leaves are at same level
Given a Binary Tree, check if all leaves are at same level or not.
          12
        /    \
      5       7       
    /          \ 
   3            1
  Leaves are at same level

          12
        /    \
      5       7       
    /          
   3          
   Leaves are Not at same level


          12
        /    
      5             
    /   \        
   3     9
  /      /
 1      2
 Leaves are at same level

 */

#include<iostream>
using namespace std;

struct Node {

	int data;
	Node * left, * right;
};

Node * get_node(int data){

	Node * node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}


bool check(Node * root, int level, int &leaf_level){

	if(root == NULL)
		return true;

	if(root->left == NULL && root->right == NULL){
		if(leaf_level == 0){
			leaf_level = level;
			return true;
		}
		else{
			return (level == leaf_level);
		}
	}

	return (check(root->left, level+1, leaf_level) &&
	check(root->right, level+1, leaf_level));
}



int main(){

	Node * root = get_node(1);
	root->left = get_node(2);
	root->left->left = get_node(3);
	root->right = get_node(4);

	int leaf_level = 0;
	cout << check(root,0,leaf_level);

	return 0;
}
