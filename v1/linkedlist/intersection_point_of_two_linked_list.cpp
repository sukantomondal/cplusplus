/*Write a function to get the intersection point of two Linked Lists
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
	return node;
}


int length(Node * head){

	if(head ==NULL){
		return 0;
	}
	
	return 1 + length(head->next);
}

int find_intersection_point(Node * head1, Node * head2){


	int l1 = length(head1);
	int l2 = length(head2);


	if(l1 >= l2 ){

		int diff = l1 -l2;
		int c = 0;

		while(c != diff){
			head1 = head1->next;
			c++;
		}

	}
	else{

		int diff = l2 - l1;
		int c = 0;
		 while( c!= diff ){
			 head2 = head2->next;
			 c++;
		 }

	}

	while (head1!=NULL && head2 != NULL){

		if(head1->data == head2->data){
				return head1->data;
		}

		head1 = head1->next;
		head2 = head2->next;
	}

	return -1;
}

int main(){


	Node * head1 = get_new_node(3);
	head1->next = get_new_node (6);
	head1->next->next = get_new_node(9);
	head1->next->next->next = get_new_node(15);
	head1->next->next->next->next = get_new_node(30);

	Node * head2 = get_new_node (10);
	head2->next = head1->next->next->next;


	cout << "Intersection point : " << find_intersection_point(head1,head2) << "\n";
}
