/*Check if a word exists in a grid or not
Given a 2D grid of characters and a word, the task is to check if that word exists in the grid or not. A word can be matched in 4 directions at any point.

The 4 directions are, Horizontally Left and Right, Vertically Up and Down.
Examples:

Input:  grid[][] = {"axmy",
                    "bgdf",
                    "xeet",
                    "raks"};
Output: Yes

a x m y
b g d f
x e e t
r a k s

Input: grid[][] = {"axmy",
                   "brdf",
                   "xeet",
                   "rass"};
Output : No

*/

#include<iostream>
#include<vector>
using namespace std;

bool find_pat(vector<string>words, int i, int j, string pat, int level){

	if(i < 0 ||i >= words.size() || j >= words[0].length() || j < 0)
		return false;
	
	//cout << words[i][j] << "\n";

	if(pat[level] != words[i][j])
		return false;

	if(level == pat.length()-1)
		return true;

	words[i][j] = '#';

	return (find_pat(words, i,j+1,pat, level+1) ||
		find_pat(words, i, j-1, pat, level+1) ||
	        find_pat(words, i+1, j , pat, level+1) ||
		find_pat(words , i-1, j, pat, level+1));	
}

int main(){

	vector<string> words = {"axmy","bgdf","xeet","raks"};

	cout << find_pat(words,1,1,"geeks",0);

	return 0;
}
