/*Pattern Searching using a Trie of all Suffixes
*/


#include<iostream>
#include<vector>
using namespace std;

#define MAX_CHAR 26


struct Tnode{

	vector<int> indices; // suffix index
	Tnode *child [MAX_CHAR];
};


Tnode * get_new_node(){

	Tnode * tnode = new Tnode;
	for(int i = 0 ; i < MAX_CHAR; i++){
		tnode->child[i] == NULL; 
	}
}

void insertTrie(Tnode * root, string word, int index){

	Tnode * head = root;

	for(char &c : word){

		if(head->child[c-'a'] == NULL){
			head->child[c-'a'] = get_new_node();
		}

		head->indices.push_back(index); // save the index
		head = head->child[c-'a'];
	}

}


void search_pattern(Tnode * root, string pattern){

	Tnode * head = root;

	for(char &c : pattern){

		if (head->child[c-'a'] == NULL){
			cout << "Patterent not found" <<  "\n";
			return;
		}
		head = head->child[c-'a'];
	}

	cout << "patteren found at " << "\n";

	for(auto x : head->indices){
		cout << x << " ";
	}

	cout << "\n";

}


int main(){

	string text = "geekforgeek";
	int l =  text.length();

	Tnode * root = get_new_node();

	for(int i = 0; i < l; i++){
		string suffix_str = text.substr(i);
		cout  << suffix_str << "\n";
		insertTrie(root, suffix_str,i);	
	}

	search_pattern(root, "for");

	return 0;
}
