/*Split a Circular Linked List into two halves
*/


#include<iostream>
using namespace std;

struct Node{
	int data;
	Node * next;
	Node(int data) : data(data), next(NULL){};
};


void print(Node * head){
	if(head == NULL)
		return;
	Node * curr = head->next;

	
	cout << head->data << " ";

	while(curr != head){
		cout << curr->data << " ";
		curr = curr->next;
	}

	cout << "\n";
}


Node * split(Node * head){

	Node * first = head;
	Node * slow = head;

	while(first->next != head && first->next->next!= head){
		slow = slow->next;
		first = first->next->next;	
	}

	Node * head2 = slow->next;
	slow->next = head;


	cout << head2->data << "\n";

	if(first->next == head)
		first->next= head2;
	else{
		first->next->next = head2;
	}

	print(head);
	print(head2);
}

int main(){

	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = head ;//new Node(5);
	//head->next->next->next->next->next = head;

	print(head);

	split(head);

	return 0;
}
