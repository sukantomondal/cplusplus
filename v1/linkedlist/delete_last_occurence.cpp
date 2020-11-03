/*Delete last occurrence of an item from linked list
*/


#include<iostream>
using namespace std;

struct Node{
	int data;
	Node * next;
};


Node * get_node(int data){

	Node * node = new Node();
	node->data = data;
	node->next = NULL;
}


void delete_last_occrence(Node * &head, int x){

	Node * curr = head;
	Node * pre = NULL;
	Node * last_occur = NULL;
	Node * last_occur_pre = NULL;


	while(curr != NULL){

		if(curr->data == x){
			last_occur_pre = pre;
			last_occur = curr;
		}
		pre = curr;
		curr = curr->next;
	}

	if(last_occur != NULL && last_occur != head){
		last_occur_pre->next = last_occur->next;
	}else if(last_occur != NULL && last_occur== head){
		head = head->next;
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
	struct Node* head = get_node(1);
    	head->next = get_node(2);
   	head->next->next = get_node(3);
    	head->next->next->next = get_node(4);
   	head->next->next->next->next = get_node(5);
    	head->next->next->next->next->next = get_node(4);
    	head->next->next->next->next->next->next = get_node(4);

	print(head);

	delete_last_occrence(head, 4);
	print(head);

	return 0;

}
