/* clone linked list with random pointer*/

#include<iostream>
using namespace std;

struct Node {
	int data;
	Node * next , * random;
};

Node * get_node(int data){

	Node * node = new Node();
	node->data = data;
	node->next= NULL;
	node->random = NULL;
}

void print(Node * head){

	if(head == NULL){
		cout << "\n";
		return;
	}

        cout << "["<< head->data << " ";
	if(head->random){
		cout << head->random->data;
	}
	else{
		cout << "NULL";
	}
	cout << "]";

	print(head->next);
}

Node * copy_list(Node * head){

	if(head == NULL)
		return NULL;
	Node * clone_node = get_node(head->data);
	clone_node->next = copy_list(head->next);
	return clone_node;
}

void clone_list(Node * head, Node * clone_head){

	Node *curr = head;
	Node *curr_clone = clone_head;

	while(curr != NULL && curr_clone != NULL){

		Node * temp = curr->next;
		curr->next = curr_clone;
		curr_clone->random= curr;
		curr = temp;
		curr_clone = curr_clone->next;
	}

	curr_clone = clone_head;

	while(curr_clone != NULL){

		if(curr_clone->random->random != NULL){
			curr_clone->random = curr_clone->random->random->next;
		}
		else{
			curr_clone->random = NULL;
		}

		curr_clone = curr_clone->next;
	}

}


int main(){

	Node * head = get_node(1);
	head->next = get_node(2);
	head->next->next = get_node(3);
	head->next->next->next = get_node(4);
	head->next->next->next->next = get_node(5);

	head->random= head->next->next;
	head->next->random = head->next->next->next;
	head->next->next->next->random= head;

	print(head);
	Node * clone_head = copy_list(head);

	clone_list(head,clone_head);

	print(clone_head);

	return 0;
}
