/*Remove duplicates from a sorted linked list
Write a function which takes a list sorted in non-decreasing order and deletes any duplicate nodes from the list. The list should only be traversed once.
*/

#include<iostream>
using namespace std;

struct Node {

	int data;
	Node * next;
};

Node * get_new_node(int data){

	Node * new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void remove_duplicate(Node *&head){

	Node *temp = head;
	while(temp!=NULL){
		if(temp->next != NULL && temp->next->data == temp->data){
			temp->next=temp->next->next;
			continue; // do not increase head
		}
		temp= temp->next;
	}
}



void print(Node * head){

	if(head == NULL){
		cout << "\n";
		return;
	}
	cout << head->data << " ";
	print(head->next);
}

int main(){

	Node * head = get_new_node(11);
	head->next = get_new_node(11);
	head->next->next= get_new_node(11);
	head->next->next->next = get_new_node(12);
	head->next->next->next->next = get_new_node(12);
	head->next->next->next->next->next = get_new_node(13);
	print(head);
	remove_duplicate(head);
	print(head);

	return 0;
}

