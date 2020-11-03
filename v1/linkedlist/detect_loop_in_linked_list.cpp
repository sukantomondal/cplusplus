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

Node* insert(Node * head, int data){

	Node * new_node = get_new_node(data);
	new_node->next = head;
	return new_node;
}

void reverse(Node *head , Node *&result){
	if(head==NULL){
		return;
	}
	result = insert(result,head->data);
	reverse(head->next,result);
	return;
}

void print(Node * head){

	if(head == NULL){
		cout << "\n";
		return;
	}
	cout << head->data << " ";
	print(head->next);
}


bool detect_loop(Node * head){

	Node * first = head;
	Node * second = head;

	while(first != NULL && second != NULL){

		if(second->next != NULL){
			second = second->next->next;
		}
		else{
			return false;
		}

		first = first->next;

		if(first == second)
			return true;
	}

	return false;
}


int main(){

	Node *head = get_new_node(1);
	head->next = get_new_node(2);
	head->next->next = get_new_node(3);
	//head->next->next->next = head->next;

	Node * result = NULL;

	//print(head);
	//reverse(head,result);
	//print(result);
	cout << "Is Loop " << detect_loop(head) << "\n";

	return 0;
}
