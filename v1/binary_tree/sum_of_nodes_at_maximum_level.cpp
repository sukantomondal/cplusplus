/*Sum of nodes at maximum depth of a Binary Tree 
 *
 * Given a root node to a tree, find the sum of all the leaf nodes which are at maximum depth from root node.

Example:

      1
    /   \
   2     3
  / \   / \
 4   5 6   7

Input : root(of above tree)
Output : 22

Explanation:
Nodes at maximum depth are: 4, 5, 6, 7.
So, sum of these nodes = 22

Input:
                1
              /   \
             2     3
              \    /
               4  5
                  \
                   6
                  / \
                 7   8

Output : 15		 
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

void sum_at_maximum_level(Node * root , int level, int &max_level,int &sum){

	if(root == NULL)
		return;
	if(level> max_level){
		max_level = level;
		sum = root->data;
	}else if(max_level == level){
		sum += root->data;
	}
	sum_at_maximum_level(root->left,level+1,max_level,sum);
	sum_at_maximum_level(root->right,level+1,max_level,sum);
}

int main(){

	Node * root = get_new_node(1);
	root->left = get_new_node(2);
	root->right =get_new_node(3);
	root->left->right = get_new_node(4);
	root->right->left = get_new_node(5);
	root->right->left->right = get_new_node(6);
	root->right->left->right->left = get_new_node(7);
	root->right->left->right->right = get_new_node(8);

	int max_level = INT8_MIN;

	int sum = 0;
	sum_at_maximum_level(root , 0, max_level,sum);

	cout << "max level : " <<max_level << " Sum : " << sum << "\n";

	return 0;
}
