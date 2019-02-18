/*Author : Sukanto Mondal */

/* 
Find Minimum Depth of a Binary Tree

Given a binary tree, find its minimum depth. The minimum depth is the number of nodes along the shortest path from root node down to the nearest leaf node. 
*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Node{

	int data;
	Node *left;
	Node *right;
};


struct qitem{

	Node *node;
	int depth;
};


int min_depth(Node *node){

	if(node == NULL)
		return 0;
	if(node->left== NULL && node->right == NULL)
		return 1;
	if(node->left == NULL)
		return min_depth (node->right) + 1;
	if(node->right == NULL)
		return min_depth (node->left) + 1;
	if(node->left!= NULL && node->right != NULL)
		return min(min_depth(node->left),min_depth(node->right))+1;

}


/* Another way without recursion using itrative way */



int min_depth_it(Node* node) {
	if (node == NULL)
		return 0;

	queue<qitem> q;

	qitem qi = {node, 1};
	q.push(qi);

	while(!q.empty()){
		qitem tqi = q.front();
		q.pop();

		Node *tnode = tqi.node;
		int dp = tqi.depth;
		cout << "Depth" << dp << "\n";

		if(tnode->left == NULL && tnode->right == NULL)
			return dp;
		if(tnode->left != NULL){
			tqi.node = tnode->left;
			tqi.depth = dp +1;
			q.push(tqi);
		}
		if(tnode->right != NULL){
			tqi.node = tnode->right;
			tqi.depth = dp +1;
			q.push(tqi);
		}
	}	
}





Node * new_node(int d){
	Node * temp = new Node;
	temp->data = d;
	temp->left = NULL; temp->right = NULL;
	return temp;
}

int main(){
	Node * root = new_node(1);
	root->left = new_node(2);
	root->right= new_node(3);
	root->left->left = new_node(4);
	root->left->right = new_node(5);
	//root->right->right= new_node(6);
	cout << "The min depth is : " << min_depth(root) << "\n";

	cout << "The min depth using level traversal is: " << min_depth_it(root) << "\n";


	return 0;
}
