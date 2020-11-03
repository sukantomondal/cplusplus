/*check a linked list is plaindrome or not */

#include<iostream>
using namespace std;

struct Node {

	char data;
	Node * next;
};

Node * get_new_node(char data){

	Node * node = new Node();
	node->data = data;
	node->next = NULL;
}


bool is_plaindrome(Node * head1){

	Node * first= head1;
	Node * second = head1;

	Node * head2;


	// divide the link list in the middle
	
	while(1){

		if(second ->next != NULL){
			second = second->next->next;
		}
		else if(second->next == NULL){  // odd numbers nodes
			head2 = first->next->next;
			first->next = NULL;
			break;
		}

		if(second == NULL) // even number of nodes
		{

			head2 = first->next;
			first->next = NULL;
			break;
		}

		first=first->next;
	}



	// reverse the second link list
	
	Node * curr = head2;
	Node  * pre = NULL;
	Node * next = NULL;

	while (curr != NULL){

		next = curr->next;
		curr-> next = pre;
		pre = curr;
		curr = next;
	}
	
	head2 = pre;


	// check plainedrome or not
	while(head1!=NULL){
		if(head1->data != head2->data){
			return false;
		}
		head1=head1->next;
		head2=head2->next;
	}
	return true;
}





void print(Node * head){

	if(head == NULL){
		cout << "\n";
		return;
	}
	
	cout << head->data << " ";
	print(head->next);
}

bool is_palindrome_with_extra_space (Node * head){
	
	Node * node = head;
	Node * head2 =NULL;

	while (node !=NULL){
		Node * temp = get_new_node(node->data);
		
		temp->next = head2;
		head2 = temp;

		node = node->next;
	}

	while(head !=NULL && head2 != NULL){

		if(head->data != head2->data){
			return false;
		}
		head = head->next;
		head2 = head2->next;
	}

	return true;
}


int main(){


	Node *head = get_new_node('a');
	head->next = get_new_node('b');
	head->next->next = get_new_node('b');
	head->next->next->next = get_new_node('a');
	head->next->next->next->next = get_new_node('c');

	cout << "Is plaindrome " << is_plaindrome(head) << "\n"; // optimize solution

	//cout << is_palindrome_with_extra_space(head);
    	
	return 0;

}
