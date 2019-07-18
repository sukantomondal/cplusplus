/*Find the k most frequent words from a file
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

#define MAX_CHAR 26

struct Tnode{

	bool isEnd;
	int no_of_occurence;
	Tnode *child [26];
};

struct qnode{
	string word;
	int no_of_occurence;
};


bool compare(qnode q1, qnode q2)
{
    return q1.no_of_occurence < q2.no_of_occurence;
}


Tnode * get_new_tnode(){

	Tnode *tnode = new Tnode;
	tnode->isEnd =false;
	tnode->no_of_occurence = 0;

	for(int i = 0; i< 26; i++){
		tnode->child[i]=NULL;
	}

	return tnode;
}

void insert_word(Tnode *root, string word, priority_queue<qnode,vector<qnode>, decltype(&compare)> &pq){

	Tnode *head = root;

	for(char &c : word){
		if(head->child[c-'a'] == NULL){
			head->child[c-'a'] = get_new_tnode();
		}
		head = head->child[c-'a'];
	}

	if(!head->isEnd)
		head->isEnd = true;
	head->no_of_occurence += 1; 

	qnode qn;
	qn.word = word;
	qn.no_of_occurence = head->no_of_occurence;
	pq.push(qn);
}

int search_word(Tnode *root, string word){

	Tnode * head = root;

	for(char &c : word){
		
		if(head->child[c-'a'] != NULL){
			head= head->child[c-'a'];
		}
		else{
			return 0; // not found the word
		}
	}

	if(head->isEnd){
		return head->no_of_occurence;
	}

	return 0;
}

void insert_in_unordered_map(unordered_map<string,int> &umap,string word){


	unordered_map<string,int>::iterator it = umap.find(word);

	if(it==umap.end()){
		umap.insert({{word,1}});
	}
	else{
		umap.insert({{word,it->second++}});
	}

}

int main(){

	Tnode * root = get_new_tnode();
	string word = "abc";

	priority_queue<qnode,vector<qnode>, decltype(&compare)> pq(&compare);

	unordered_map<string,int> umap;

	vector<string> word_arr = {"aaa","aaa", "aaaan","dddd", "ddffd", "dddd"};

	for(string &word : word_arr){
		insert_word(root,word,pq);
		insert_in_unordered_map(umap,word);
	}

	while(!pq.empty()){

		qnode qn = pq.top();
		cout << qn.word << " == " << qn.no_of_occurence << "\n";
	       	pq.pop();	
	}

	/*for(string &word : word_arr){
		cout << word  << " " << search_word(root, word) << "\n";
	}
	*/

	vector<qnode> words;

	cout << "unsorted frequency\n";
	for (auto &it : umap){
		qnode qn = {it.first,it.second};
		cout << it.first << "  " << it.second << "\n";
		words.push_back(qn);
	}

	sort(words.begin(),words.end(),compare);


	cout << "sorted frequency\n";

	for(auto &it : words){
		cout << it.word << "  " << it.no_of_occurence << "\n";
	}


	return 0;
}
