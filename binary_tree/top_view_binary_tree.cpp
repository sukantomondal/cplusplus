/*Author : Sukanto Mondal */

/*
Print Nodes in Top View of Binary Tree

Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. Given a binary tree, print the top view of it. The output nodes can be printed in any order. Expected time complexity is O(n)

A node x is there in output if x is the topmost node at its horizontal distance. Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1, and that of right child is horizontal distance of x plus 1. 
*/

#include<iostream>
#include<queue>
#include<map>
using namespace std;

struct Node{
	int data;
	Node * lchild, * rchild;
	int hd;
};


void print_top_view(Node * root){

	queue <Node*> node_queue;
	map<int,Node*> node_map;

	root->hd = 0;
	node_queue.push(root);
	
	while(!node_queue.empty()){
	
		Node * temp = node_queue.front();
		node_queue.pop();

		if(node_map.find(temp->hd) == node_map.end()){
			node_map[temp->hd] = temp;
		}

		if(temp->lchild!=NULL){
			temp->lchild->hd = temp->hd-1;
			node_queue.push(temp->lchild);
		}
		if(temp->rchild!=NULL){
			temp->rchild->hd = temp->hd +1;
			node_queue.push(temp->rchild);
		}
	}

	for(auto&x: node_map)
		cout << x.second->data << " ";
	cout << "\n";

}

Node * new_node(int data){
	Node * temp = new Node();
	temp->data = data;
	temp->hd = INT8_MAX;
	temp->lchild = NULL;
	temp->rchild = NULL;
	return temp;
}
int main(){
	Node * root = new_node (1);
	root->lchild = new_node(2);
	root->rchild = new_node(3);
	root->lchild->rchild = new_node(4);
	root->lchild->rchild->rchild = new_node(5);
	root->lchild->rchild->rchild->rchild = new_node(6);

	cout << "The top view the tree is : ";
	print_top_view(root);

	return 0;
}
