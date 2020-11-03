/*Flattening a Linked List
Given a linked list where every node represents a linked list and contains two pointers of its type:
(i) Pointer to next node in the main list (we call it ‘right’ pointer in below code)
(ii) Pointer to a linked list where this node is head (we call it ‘down’ pointer in below code).
All linked lists are sorted. See the following example

       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
Write a function flatten() to flatten the lists into a single linked list. The flattened linked list should also be sorted. For example, for the above input list, output list should be 5->7->8->10->19->20->22->28->30->35->40->45->50.
*/


#include<iostream>
using namespace std;

struct Node{

	int data;
	Node * next;
	Node * down;
};

Node * get_node(int data){

	Node * node = new Node();
	node->data = data;
	node->next = NULL;
	node->down = NULL;
	return node;
}

Node * merge(Node * a , Node * b){

	
	Node * result = NULL;
	Node * result_head = result;

	if(a == NULL && b == NULL)
		return NULL;

	int num;
	while(a!=NULL &&  b!=NULL){
		if(a->data < b->data){
			num = a->data;
			a=a->down;
		}
		else {
			num = b->data;
			b=b->down;
		}

		if(result == NULL){
			result = get_node(num);
			result_head = result;
		}else{
			result->down = get_node(num);
			result = result->down;
		}
	}

	if(a==NULL){
		result->down = b;
	}

	if(b==NULL){
		result->down = a;
	}

	return result_head;
}


Node * merge_recurr(Node * a , Node * b){

	if(a==NULL){
		return b;
	}
	if(b==NULL)
		return a;

	Node * result;

	if(a->data < b->data){
		result = a;
		result->down = merge_recurr(a->down,b);
	}
	else{
		result = b;
		result->down=merge_recurr(a,b->down);
	}

	return result;
}

Node * flatten(Node * head){

	if(head == NULL || head->next == NULL)
		return head;
	return merge_recurr(head,flatten(head->next));
}

void print(Node * head){

	if(head == NULL){
		cout << "\n";
		return;
	}
	cout << head->data << " ";
	print(head->down);
}

int main(){

	Node * head = get_node(5);
	head->down = get_node(7);
	head->down->down = get_node(8);
	head->down->down->down = get_node(30);


	head->next = get_node(10);
	head->next->down = get_node(20);

	head->next->next = get_node(19);
	head->next->next->down = get_node(22);
	head->next->next->down->down = get_node(50);

	head->next->next->next = get_node(28);
	head->next->next->next->down = get_node(35);
	head->next->next->next->down->down = get_node(40);
	head->next->next->next->down->down->down = get_node(45);	

	//Node * result = merge(head,head->next);

	//Node *result = merge_recurr(head,head->next);
	//
	//
	Node *result = flatten(head);

	print(result);

	return 0;
}
