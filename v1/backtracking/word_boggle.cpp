/* word boggle */
/*Boggle | Set 2 (Using Trie)
Given a dictionary, a method to do a lookup in the dictionary and a M x N board where every cell has one character. Find all possible words that can be formed by a sequence of adjacent characters. Note that we can move to any of 8 adjacent characters, but a word should not have multiple instances of the same cell.

Example:

Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
       boggle[][]   = {{'G','I','Z'},
                       {'U','E','K'},
                       {'Q','S','E'}};
      isWord(str): returns true if str is present in dictionary
                   else false.

Output:  Following words of the dictionary are present
         GEEKS
         QUIZ
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> x ={1,1,1,0,0,-1,-1,-1}; 
vector<int> y ={-1,0,1,-1,1,-1,0,1};



bool is_word (vector<string> &dic, string str){

	for(string st : dic){
		if(st == str)
			return true;
	}

	return false;
}
bool is_safe(vector<vector<char>> &boggle, int row, int col){

	if(row>=0 && row < boggle.size() && col>=0 && col < boggle[0].size())
		return true;
	return false;
}

void search(vector<vector<char>> &boggle, vector<vector<int>> visited, vector<string> &dic , int row, int col, string str){

	
	if(is_word(dic,str)){
		cout << str << "\n";
		return;
	}

	for(int i = 0 ; i < 8; i++){
		if(is_safe(boggle, row+x[i], col+y[i]) && !visited[row+x[i]][col+y[i]]){
			visited[row+x[i]][col+y[i]] = 1;
			search(boggle,visited,dic,row+x[i], col+y[i], str+boggle[row+x[i]][col+y[i]]);
			visited[row+x[i]][col+y[i]] = 0;
		}
	}
}


void search_words(vector<vector<char>> &boggle, vector<string> &dic){

	for(int i= 0 ; i < boggle.size(); i++ ){
		for(int j = 0 ; j < boggle[0].size(); j++){
			vector<vector<int>> visited(boggle.size(),vector<int>(boggle[0].size()));
			search(boggle, visited, dic, i, j, ""+boggle[i][j]);
		}
	}

}


int main(){
	vector<string> dic = {"GEEKS", "FOR", "QUIZ", "GO"};
	vector<vector<char>> boggle = {{'G', 'I', 'Z'}, {'U', 'E', 'K'}, {'Q', 'S', 'E'}};
	search_words(boggle, dic);
	return 0;
}
