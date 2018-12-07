#include <iostream>
#include <vector>
#include <unordered_map>
#include <array>

using namespace std;

struct node {
	char c;
	node * parent;
	array <node*, 26> childs;
	vector<int> word_occerence;
};


void insert_word (node * head, string word, int index){

	node * traverse = head;
	for (char& c : word ){
		
		if (traverse->childs[c-'a'] == NULL){
			node * cnode = new node();
        		cnode->c = c;
			cnode->parent = traverse;
        		traverse->childs[c-'a'] = cnode;
			traverse = cnode; 
		}else{
			traverse = traverse->childs[c-'a'];
		}

		if(word.back() == c){
			traverse->word_occerence.push_back(index);
		}

	}

}




bool search_tries(node * head, string word){

	node * traverse = head;

	for(char &c : word){

		cout<< traverse->c << "\n";

		if((word.back() == c) && (traverse->word_occerence.size() == 0))
			return true;

		if((word.back() != c) && traverse->childs[c-'a'] == NULL){

			cout << "got null pointer \n";
			return false;
		}
		else{
			traverse = traverse->childs[c-'a'];
		}	
	}
	
	return false;
}



int main ()
{
	cout << "Making a trie tree\n";
	
	node * head = new node();
	head->c = '/'; // root char

	string word = "tesp";
		
	insert_word(head, word, 1);
	insert_word(head, "temp", 2);


	bool r = search_tries(head,"tespu");


	if(r){

		cout << "Found";
	}
	else{
	
		cout << "Not Found";
	}

	/*while(true){

		cout << head->c;

		bool is_child_exist = false;
		node * next = new node();

		for(int i = 0 ; i < 26 ; i++){
			
			if(head->childs[i] != NULL){	
				is_child_exist = true;
				next = head->childs[i];
				break;
			}
		}

		if (!is_child_exist){
			cout << "Found a word \n";
			break;
		
		}
		
		head = next;

	}*/

	
	return 0;
}
