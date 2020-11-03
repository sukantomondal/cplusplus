/* Author: Sukanto Mondal*/
/*Given a binary tree, find the maximum path sum. The path may start and end at any node in the tree.

Example:

Input: Root of below tree
       1
      / \
     2   3
Output: 6

See below diagram for another example.
1+2+3
*/

#include<iostream>
#include<algorithm>

using namespace std;

struct Node {

	int data;
	Node *lchild, *rchild;
};

bool preorder(Node * root){
	if(root==NULL)
		return false;
	cout<<root->data << " ";
	preorder(root->lchild);
	preorder(root->rchild);
}

int max_path_sum(Node * root, int &current_max){

	if(root==NULL)
		return 0;

	int l = max_path_sum(root->lchild,current_max);
	int r = max_path_sum(root->rchild,current_max);

	int max_single = max(max(l,r)+root->data, root->data);

	int max_top = max(max_single,l+r+root->data);
	
	current_max = max(current_max,max_top);

	return max_single;
}

Node * new_node (int data){
	Node *temp = new Node();
	temp->data = data;
	temp->lchild = NULL;
	temp->rchild= NULL;
	return temp;
}

int main(){
	Node * root = new_node(10);
	root->lchild = new_node(2);
       	root->rchild = new_node(10);
	root->lchild->lchild = new_node(20);
	root->lchild->rchild = new_node(1);
	root->rchild->rchild = new_node(-25);
	root->rchild->rchild->lchild = new_node(3);
	root->rchild->rchild->rchild = new_node(4);

	preorder(root);

	int current_max = INT8_MIN;
	max_path_sum(root,current_max);
	cout << "The maximum sum path is  : " << current_max << "\n"; 
	return 0;
}
