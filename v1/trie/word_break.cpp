/*Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words. See following examples for more details.

Consider the following dictionary
{ i, like, sam, sung, samsung, mobile, ice,
  cream, icecream, man, go, mango}

Input:  ilike
Output: Yes
The string can be segmented as "i like".

Input:  ilikesamsung
Output: Yes
The string can be segmented as "i like samsung" or "i like sam sung".
*/

#include<iostream>
#include<vector>
using namespace std;

struct Node {
	bool is_end;
	Node * child[26];
};

Node * new_node(){
	Node * node = new Node();
	node->is_end = false;
	for(int i = 0 ; i< 26 ; i++){
		node->child[i] = NULL;
	}
}


void make_trie(vector<string> words, Node * &root){
	Node * curr = root;
	for(string str : words){
		curr= root;
		for (char x : str){
			if(curr->child[x-'a'] == NULL){
				curr->child[x-'a'] = new_node();
			}
			curr=curr->child[x-'a'];
		}
		curr->is_end = true;
	}

}


bool check_word(Node * &root , string key){

	Node *curr = root;
	for(char x : key){
		cout << x ;
		if(curr->child[x-'a'] != NULL){

			if(curr->child[x-'a']->is_end){
				curr= root;
				cout <<"*";
			}else{
				curr = curr->child[x-'a'];
			}
		}
		else{
			return false;
		}
	}

	return (curr == root);
}


int main(){

	vector<string> words = {"i", "like", "sam", "sung", "samsung", "mobile", "ice", "cream", "icecream", "man", "go", "mango"};
	Node * root = new_node();
	make_trie(words, root);
	string key = "ilikesamsung";

	cout << check_word(root,key) << "\n";
	return 0;
}
