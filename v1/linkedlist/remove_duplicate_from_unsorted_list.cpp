/*Remove duplicates from an unsorted linked list
Write a removeDuplicates() function which takes a list and deletes any duplicate nodes from the list. The list is not sorted.
For example if the linked list is 12->11->12->21->41->43->21 then removeDuplicates() should convert the list to 12->11->21->41->43.

*/

#include<iostream>
#include<unordered_set>
using namespace std;

struct Node {

	int data;
	Node * next;
};

Node * get_new_node(int data){

	Node * new_node = new Node ();
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void remove_duplicate(Node * &head){
	
	unordered_set<int> hash;
	
	Node * temp = head;
	Node * pre = NULL;
	
	while(temp!=NULL){

		if(hash.find(temp->data) == hash.end()){
			hash.insert(temp->data);
			pre = temp;
			temp = temp->next;
		}
		else{
			// two ways you can delete the node
			// option : 1
			//pre->next= temp->next;
			//temp= pre->next;
			
			// option :2
			temp= temp->next;
			pre->next=temp;
		}
		
	}
	
}

void print(Node * head){
	
	while(head!=NULL){
		cout << head->data << " ";

		head= head->next;
	}
	cout << "\n";
}

int main(){

	Node * head = get_new_node(12);
	head->next = get_new_node(11);
	head->next->next = get_new_node(12);
	head->next->next->next = get_new_node(21);
	head->next->next->next->next = get_new_node(41);
	head->next->next->next->next->next = get_new_node(43);
	head->next->next->next->next->next->next = get_new_node(21);

	print(head);

	remove_duplicate(head);
	print(head);
	return 0;
}
