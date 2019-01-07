#include <iostream>
#include <vector>
#include <unordered_map>
#include <array>

/*Some useful information about interview practice:
[2:15 PM] Douglas Bisiw: this course: Grokking the System Design Interview
[2:15 PM] Douglas Bisiw: from: https://www.educative.io
[2:15 PM] Douglas Bisiw: and
[2:16 PM] Douglas Bisiw: and this has the 65 questions
[2:16 PM] Douglas Bisiw: https://www.algoexpert.io/product
[2:17 PM] Douglas Bisiw: and you can practice from this website
[2:17 PM] Douglas Bisiw: https://www.interviewbit.com/
[2:18 PM] Douglas Bisiw: and if you want, this too
[2:18 PM] Douglas Bisiw: https://www.dailycodingproblem.com
*/

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
