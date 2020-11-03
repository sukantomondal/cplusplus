/* Author : Sukanto Mondal */

/*Find Duplicate in a Binary Matrix
Given a binary matrix whose elements are only 0 and 1, we need to print the rows which are duplicate of rows which are already present in the matrix.
Examples:
Input : {1, 1, 0, 1, 0, 1},
    {0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 0, 0},
    {1, 1, 0, 1, 0, 1},
    {0, 0, 1, 0, 0, 1},
    {0, 0, 1, 0, 0, 1}.

Output :
There is a duplicate row at position: 4
There is a duplicate row at position: 5
There is a duplicate row at position: 6
*/

#include <iostream>
#include <vector>

using namespace std;

struct Trie{
	bool leaf;
	int val;
	Trie *child[2];
};

Trie* get_new_node(){
	
	Trie *node = new Trie;
       	node->leaf= false;
       	node->child[0] = NULL;
       	node->child[1] = NULL;
	return node;
}

void print_array(vector<int> arr){
       	for(int i=0; i< arr.size(); i++){
		cout<< arr[i] << " ";
        }
        cout << "\n";
}

bool insert(Trie* head, vector<int> arr){

	Trie * curr = head;
	
	for(int i = 0; i< arr.size(); i++){

		if(curr->child[arr[i]] == NULL){
			curr->child[arr[i]] = get_new_node();
		} 

		curr = curr->child[arr[i]];
	}

	if(curr->leaf)
		return false;

	curr->leaf = true;

	return true;
}



void print_duplicate_row(Trie *head, vector<vector<int>> mat){

	for (int i = 0 ; i < mat.size(); i++){
		vector<int> mrow = mat[i];
		if(!insert(head,mrow)){
			cout << "Duplicate row found in row : " << i +1 << "\n";
			print_array(mrow);
		}
	}
}

int main (){
	Trie *head = get_new_node();
	vector<vector<int>> mat = {{1,1,0,1,0,1},{0,0,1,0,0,1},{1,0,1,1,0,0},{1,1,0,1,0,1},{0,0,1,0,0,1},{0,0,1,0,0,1}};
	print_duplicate_row(head,mat);
	return 0;
}
