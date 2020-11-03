/*Count of number of given string in 2D character array
Given a 2-Dimensional character array and a string, we need to find the given string in 2-dimensional character array such that individual characters can be present left to right, right to left, top to down or down to top.

Examples:

Input : a ={
            {D,D,D,G,D,D},
            {B,B,D,E,B,S},
            {B,S,K,E,B,K},
            {D,D,D,D,D,E},
            {D,D,D,D,D,E},
            {D,D,D,D,D,G}
           }
        str= "GEEKS"
Output :2
*/


#include <iostream>
#include <vector>
using namespace std;

int search(vector<vector<char>> chr2d, string pat, int row, int col){

	int max_row = chr2d.size();
	int max_col = chr2d[0].size();

	/*int found = 0;


	if(row >= 0 && row < max_row && col>= 0 && col < max_col && chr2d[row][col] == pat[0]){

		if(pat.length()==1){
			found = 1;
		}
		else{
			pat = pat.substr(1);
			cout << "pat " << pat << "\n";
			found += search(chr2d,pat,row,col+1);
			found += search(chr2d,pat,row+1,col+1);
			found += search(chr2d,pat,row+1,col);
			found += search(chr2d,pat,row+1,col-1);
			found += search(chr2d,pat,row,col-1);
			found += search(chr2d,pat,row-1,col-1);
			found += search(chr2d,pat,row-1,col);
			found += search(chr2d,pat,row-1,col+1);
		}
		
		
	}
	return found 
	*/




	int found = 0;
	vector<int> x = {0,1,1,1,0,-1,-1,-1};
	vector<int> y = {1,1,0,-1,-1,-1,0,1};


	if(chr2d[row][col] == pat[0] && pat.length() == 1){
		return 1;
	}

	if(chr2d[row][col] == pat[0]){

		int dir = 0;
		pat = pat.substr(1);

		int rd,cd;

		for(dir=0; dir < 8; dir++){

			rd = row+x[dir]; cd = col+y[dir];
			bool isfound = true;

			for(char &c : pat){
				if (rd >= 0 && rd < max_row && cd>= 0 && cd < max_col && c==chr2d[rd][cd]){
					rd += x[dir];
					cd += y[dir];
				}
				else{
					isfound = false;
					break;
				}
			}

			if (isfound)
				found+=1;
		}

	}

	return found;
}

int pattern_search(vector<vector<char>> chr2d, string pat){
	int found = 0;

	for (int i = 0 ; i < chr2d.size(); i++){
		for(int j = 0 ; j < chr2d[0].size(); j++){
			found += search(chr2d,pat, i, j);
		}
	}

	return found;

}

int main(){
	vector<vector<char>> chr2d = {{'a','s','d'},{'d','d','a'}};
	cout << pattern_search(chr2d, "ad");
	return 0;
}

