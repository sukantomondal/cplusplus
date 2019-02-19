/* Author : Sukanto Mondal */

/*
Bottom View of a Binary Tree

Given a Binary Tree, we need to print the bottom view from left to right. A node x is there in output if x is the bottommost node at its horizontal distance. Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1, and that of right child is horizontal distance of x plus 1. 
*/


#include<iostream>
#include<queue>
#include<map>

using namespace std;

struct Node {
	int data;
	int hd;
	Node * lchild, * rchild;
};

void print_bottom_view(Node * root){

	queue<Node*> node_queue;
	root->hd = 0;
	node_queue.push(root);
	map<int,Node*,less<int>> node_map; // index are ordered for map

	while(!node_queue.empty()){
		Node * temp = node_queue.front();
		node_queue.pop();
		node_map[temp->hd] = temp;

		if(temp->lchild!=NULL){
			temp->lchild->hd = temp->hd-1;
			node_queue.push(temp->lchild);
		}
		if(temp->rchild!=NULL){
			temp->rchild->hd = temp->hd+1;
			node_queue.push(temp->rchild);
		}
	}


	/*for (auto i = node_map.begin(); i != node_map.end(); ++i)
        	cout << i->second->data << " ";
	*/
	for(auto &x: node_map){
		cout << x.second->data << " ";
	}

	cout<< "\n";
}


void print_level_order(Node * root){

	queue<Node*> node_queue;
	node_queue.push(root);

	while(!node_queue.empty()){
		Node * temp = node_queue.front();
		node_queue.pop();
		cout<< temp->data << "\n";
	       	if(temp->lchild!=NULL)
			node_queue.push(temp->lchild);
		if(temp->rchild!=NULL)
			node_queue.push(temp->rchild);		
	}

}


Node * new_node(int data){
	Node * temp = new Node();
	temp->data = data;
	temp->lchild = NULL;
	temp->rchild = NULL;
	temp->hd = INT8_MAX;
	return temp;
}

int main(){

	Node * root = new_node(20);
	root->lchild = new_node(8);
	root->rchild = new_node(22);
	root->lchild->lchild = new_node(5);
	root->lchild->rchild = new_node(3);
	root->lchild->rchild->lchild = new_node(10);
	root->lchild->rchild->rchild = new_node(14);
	root->rchild->rchild = new_node(25);
	//print_level_order(root);
	cout << "The bottom view of the tree is : ";
	print_bottom_view(root);
	return 0;
}
