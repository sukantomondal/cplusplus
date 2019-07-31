#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};


void print_linked_list (node *head) {

    while(true){
	   cout << head->data;
	   if(head->next == NULL){
	    	break;
	   }
	   else{
	   	cout << "-->";
	   }

	   head = head->next;
    }
}

int main() 
{
    int a; // Enter 0 to end the input.
    cout << "Creating a linked list\n";
    node* head =  new node(); 
    head->data = 0;
    node* curr = new node();
    while(true)
    {                                     
	    cin >> a;
	    if ( a == 0){
	        break;
	    }
	    node* temp = new node();
	    temp->data = a;
	    temp->next = NULL;
	    
	    if(head->data ==  0){
	    	 head = temp;
	 	 curr = temp;
	    }
	    else{
		  curr->next = temp;
		  curr = temp;
	    }
	    
    }

    print_linked_list(head);

    return 0;
}
