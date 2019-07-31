/* Add two number respresented in linked list */

#include<iostream>
using namespace std;

struct Node {

	int data;
	Node * next;
};


Node * get_new_node(int data){

	Node * node = new Node();
	node->data = data;
	node->next = NULL;
}

int length(Node * head){

	if(head==NULL){
		return 0;
	}
	else{
		return 1 + length(head->next);
	}
}

Node * insert(Node * head, int data){

	Node * new_head = get_new_node(data);
	new_head->next = head;
	return new_head;	
}


Node * sum(Node *head1, Node * head2, int &carry){

	if(head1== NULL){
		return NULL;
	}

	Node * result = get_new_node(0);

	result->next = sum(head1->next,head2->next,carry);

	int sum = head1->data + head2->data + carry;
	carry = sum / 10;
	result->data = sum%10;
	return result;
}


void print (Node * head){

	if(head == NULL){
		cout << "\n";
		return;
	}
	cout << head->data << " ";
	print(head->next);
}

int main(){

	Node * head1 = get_new_node(1);
	head1->next = get_new_node(2);
	head1->next->next = get_new_node(3);
	//head1->next->next->next = get_new_node(4);
	//head1->next->next->next->next = get_new_node(5);

	int l1 = length(head1);
	//cout << l1 << "\n";

	Node * head2 = get_new_node(9);
	head2->next = get_new_node(6);
	head2->next->next = get_new_node(3);
	head2->next->next->next = get_new_node(9);
	head2->next->next->next->next = get_new_node(9);

	int l2 = length(head2);
	//cout << l2 << "\n";

	if(l1>l2){
		int diff = l1-l2;
		for(int i = 0 ; i < diff ; i++){
			head2 = insert(head2, 0);
		}
	}
	else if(l2>l1){

		int diff = l2 - l1;

		for(int i = 0 ; i< diff; i++){
			head1 = insert(head1,0);
		}
	}

	print(head1);
	print(head2);

	int carry = 0;
	Node * result = sum(head1,head2,carry);

	if(carry != 0){
		result = insert(result,carry);
	}
	print(result);

	return 0;
}
