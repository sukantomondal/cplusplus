/*Given a singly linked list, rotate the linked list counter-clockwise by k nodes. Where k is a given positive integer. For example, if the given linked list is 10->20->30->40->50->60 and k is 4, the list should be modified to 50->60->10->20->30->40. Assume that k is smaller than the count of nodes in linked list.
 */

#include<iostream>
using namespace std;

struct Node {
	int data;
	Node * next;
};


Node * get_new_node(int data) {
	Node * node = new Node();
	node->data = data;
	node->next = NULL;
}

void print(Node * node) {

	int i = 0;
	while (node != NULL) {
		cout<< node->data << " ";
		node = node->next;
		i++;
		if(i>10)
			break;
	}

	cout << "\n";
}

Node * rotate(Node *node, int k) {
	// k is given alwayes less than the length of the linked list.
	if (k == 0) {
		return node;
	}
	Node * head = node;
	Node * new_head = node;
	int count = 0;
	while(node->next != NULL) {
		count++;
		if(count == k) {
			new_head = node->next;
			node->next = NULL;
			node = new_head;
		} 
		else {
			node = node->next;
		}
	}
	node->next = head; // make it circular
	return new_head;
}

int main() {

	Node * head = get_new_node(10);
	head->next = get_new_node(20);
	head->next->next = get_new_node(30);
	head->next->next->next = get_new_node(40);
	print(head);
		
	Node * new_head = rotate(head, 3);

	print(new_head);

	return 0;
}
