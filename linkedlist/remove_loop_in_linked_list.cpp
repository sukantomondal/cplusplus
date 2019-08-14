/*Remove loop from linked_list*/


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

void print (Node * head){

	if(head == NULL){
		cout << "\n";
		return;
	}

	cout << head->data << " ";
	print(head->next);
}



Node * detect_loop(Node * head){

	Node * fast_p = head;
	Node * slow_p = head;

	while (slow_p && fast_p && fast_p->next){

		slow_p = slow_p->next;
		fast_p = fast_p->next->next;

		if(slow_p == fast_p)
			return slow_p;
	}

	return NULL;
}

void remove_loop(Node * head){

	Node * ptr1 = head;

	Node * loop_node = detect_loop(head);
	Node *ptr2;

	if(loop_node == NULL)
		return;

	while(1){

		ptr2 = loop_node;
		while(ptr2->next!= loop_node && ptr2->next != ptr1){
			ptr2=ptr2->next;
		}

		if(ptr2->next == ptr1){
			ptr2->next = NULL;
			break;
		}

		ptr1= ptr1->next;
	}

	print(head);
}


int main(){
	struct Node* head = get_node(50); 
    	head->next = get_node(20); 
    	head->next->next = get_node(15); 
    	head->next->next->next = get_node(4); 
    	head->next->next->next->next = get_node(10); 
  
	print(head);

    	/* Create a loop for testing */
   	 head->next->next->next->next->next = head->next->next; 
  
	remove_loop(head);

	return 0;
}
