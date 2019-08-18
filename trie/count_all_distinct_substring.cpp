/*count all distinct sub string in a string */

/*
 * Count of distinct substrings of a string using Suffix Trie
Given a string of length n of lowercase alphabet characters, we need to count total number of distinct substrings of this string.
Examples:

Input  : str = “ababa”
Output : 10
Total number of distinct substring are 10, which are,
"", "a", "b", "ab", "ba", "aba", "bab", "abab", "baba"
and "ababa"
Recommended: Please solve it on “PRACTICE ” first, before moving on to the solution.
The idea is create a Trie of all suffixes of given string. Once the Trie is constricted, our answer is total number of nodes in the constructed Trie. For example below diagram represent Trie of all suffixes for “ababa”. Total number of nodes is 10 which is our answer.

*/


#include<iostream>
#include<string>
#include<vector>
using namespace std;


struct Node {
	int is_end;
	Node * child[26];
};

Node * get_node(){

	Node * node = new Node();
	node->is_end = false;
	for(int i = 0 ; i< 26; i++){
		node->child[0] = NULL;
	}
	return node;
}

void insert(Node * root, string s, int &num){

	Node * curr = root;
	for(char x : s){
		if(curr->child[x-'a'] == NULL){
			curr->child[x-'a'] = get_node();
			num++;
		}
		curr = curr->child[x-'a'];
	}
	curr->is_end = true;
}

int main(){

	string s = "ababa";

	Node * root = get_node();

	int num = 1;

	for(int i= 0; i < s.length(); i++){
		string suffix = s.substr(i,s.length()-i);
		//cout << suffix << "\n";
		insert(root,suffix,num);

		//cout << num << "\n";
	}

	cout << num ;

	return 0;
}
