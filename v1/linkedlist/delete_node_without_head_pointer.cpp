/* Author : Sukanto Mondal */


/*Delete a Node from linked list without head pointer
 *
 * You are given a singly linked list and pointer which is pointing to the node which is required to be deleted. Any information about head pointer or any other node is not given. You need to write a function to delete that node from linked list. Your function will take only one argument: pointer to the node which is to be deleted.
 *
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
	node->next = NULL;
}

void delete_node(Node * &node){

	if(node == NULL)
		return;

	if(node->next != NULL){
		node->data = node->next->data;
		node->next = node->next->next;
	}else{
		node = NULL;
	}


}

void print(Node *head){

	if(head == NULL){
		cout << "\n";
		return;
	}

	cout << head->data << " ";
	print(head->next);
}

int main(){

	Node * head = get_new_node(1);
	head->next = get_new_node(2);
	head->next->next = get_new_node(3);
	head->next->next->next = get_new_node(4);

	cout << "Before delete: \n";
	print(head->next);
	delete_node(head);
	cout << "After delete: \n";
	print(head);

	return 0;
}
