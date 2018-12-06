#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct node {
	char c;
	node * parent;
	unordered_map <char, node*> childs;
	int word_number;
};


void insert_word (node * head, string word){

	node * traverse = head;
	for (char& c : word ){
		node * temp = new node();
        	temp->c = c;
        	temp->parent = traverse;
        	pair<char, node*> children (c,temp);
        	traverse->childs.insert(children);
		traverse = temp;
	}

	/*
	if(traverse->childs.size() == 0){
		cout << "No child exist \n";
	}else{	
		cout << "child created" << traverse->childs.size();
	}*/	
	
}

int main ()
{
	cout << "Making a trie tree\n";
	
	node * head = new node();
	head->c = '/'; // root char
        head->word_number = 0; 

	string word = "test";
	insert_word(head, word);

	while(true){
		cout << head->c;
		if(head->childs.size() == 0){	
			cout << "Foun the word\n";
			break;
		}
		auto it = head->childs.begin();
		head = it->second;
	}

	return 0;
}
