/*Segregate even and odd nodes in a Linked List
Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers same.
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


void segreget_list(Node * &head){

	Node * start = head;
	Node * new_end  = head;
	Node * end_ref = NULL;
	Node * even_start = NULL;
	Node * even_end = NULL;

	while(new_end->next!=NULL){
		new_end = new_end->next;
	}

	end_ref = new_end;


	while(start != end_ref){

		if(start->data % 2 == 0){
			even_end = start;
			if(even_start==NULL)
				even_start = start;
			start = start->next;
		}
		else{
			new_end->next = start;
			if(even_end!=NULL){
				even_end->next = start->next;
			}
			start = start->next;
			new_end = new_end->next;
			new_end->next = NULL;
		}	
	}


	if(start->data % 2 == 0){ 
		head= even_start;

	}
	else{
		new_end->next = start;
		if(even_end!=NULL){
			even_end->next = start->next;
			head= even_start;	 
		}
		else{
			head = start->next;
		}

		new_end = new_end->next;
		new_end->next = NULL;	
	}

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

	Node * head = get_new_node(10);
	head->next = get_new_node(2);
	head->next->next = get_new_node(3);
	head->next->next->next = get_new_node(5);
	head->next->next->next->next = get_new_node(6);
	head->next->next->next->next->next = get_new_node(7);


	print(head);

	segreget_list(head);

	print(head);

	return 0;
}
