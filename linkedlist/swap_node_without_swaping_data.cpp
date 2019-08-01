/*Swap nodes in a linked list without swapping data
Given a linked list and two keys in it, swap nodes for two given keys. Nodes should be swapped by changing links. Swapping data of nodes may be expensive in many situations when data contains many fields.
It may be assumed that all keys in linked list are distinct.

Examples:

Input:  10->15->12->13->20->14,  x = 12, y = 20
Output: 10->15->20->13->12->14

Input:  10->15->12->13->20->14,  x = 10, y = 20
Output: 20->15->12->13->10->14

Input:  10->15->12->13->20->14,  x = 12, y = 13
Output: 10->15->13->12->20->14

*/


#include<iostream>
using namespace std;

struct Node{

	int data;
	Node * next;
};


Node * get_new_node(int data){

	Node * node = new Node();
	node->data = data;
	node->next = NULL;
}


void swap(Node *&head, int x , int y){

	

}

void print(Node *head){
	if(head==NULL){
		cout << "\n";
		return;
	}
	cout << head->data << " ";
	print( head->next);
}

int main(){

	Node *head = get_new_node(10);
       	head->next = get_new_node(15);
	head->next->next = get_new_node(12);
	head->next->next->next = get_new_node(13);
	head->next->next->next->next = get_new_node(20);
	head->next->next->next->next->next = get_new_node(14);	

	print(head);

	return 0;
}
