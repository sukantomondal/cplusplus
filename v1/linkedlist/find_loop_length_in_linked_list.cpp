/*Detect loop in a linked list
Given a linked list, check if the linked list has loop or not. Below diagram shows a linked list with a loop.
*/

#include<iostream>
using namespace std;

struct Node {

	int data;
	Node * next;
};

Node * get_new_node(int data){
	Node * node = new Node();
	node->data = data;
	node->next =NULL;
	return node;
}

int loop_length(Node * head){

	Node * first = head;
	Node * second = head;

	
	bool is_loop = false;

	while(first != NULL && second != NULL && second->next != NULL){

		second = second->next->next;

		first = first->next;

		if(first == second){
			is_loop= true;
			break;
		}
	}
	
	if(is_loop){
		Node * temp = first->next;
		int count = 1;
		while (temp != NULL && temp!=first){
			temp = temp->next;
			count++;
		}

		return count;
	}

	return -1;
}


int main(){

	Node *head = get_new_node(1);
	head->next = get_new_node(2);
	head->next->next = get_new_node(3);
	//head->next->next->next = head->next;
	
	cout << "loop length: " << loop_length(head) << "\n";

	return 0;
}
