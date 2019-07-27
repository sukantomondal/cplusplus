/* string permutation */

#include<iostream>
#include<vector>
using namespace std;


void string_permutation(string st, int level, vector<char>result, vector<int>index){

	if(level == st.size()){
		for(char x : result){
			cout << x;
		}
		cout << "\n";
		return;
	}
	for(int i = 0 ; i < st.size(); i++){	
		if(index[i] == 0){
			result[level] = st[i];
			index[i] = 1;
			string_permutation(st, level+1, result, index);
			index[i] = 0;  // backtracking here
		}
	}	
}

int main(){

	string st = "abc";

	int n = st.size();
	vector<int> index(n,0);
	vector<char>result(n);

	string_permutation(st,0,result,index);	

	return 0;
}
