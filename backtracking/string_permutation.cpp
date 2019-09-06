/* string permutation */

#include<iostream>
#include<vector>
using namespace std;

/*
 abc
level : 2
1 1 1 
level : 1
1 1 0 
acb
level : 2
1 1 1 
level : 1
1 0 1 
level : 0
1 0 0 
bac
level : 2
1 1 1 
level : 1
1 1 0 
bca
level : 2
1 1 1 
level : 1
0 1 1 
level : 0
0 1 0 
cab
level : 2
1 1 1 
level : 1
1 0 1 
cba
level : 2
1 1 1 
level : 1
0 1 1 
level : 0
0 0 1 

*/
void string_permutation(string st, int level, vector<char>result, vector<int>&index){

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

			/*cout << "level : " <<level << "\n";
			for(auto x : index){
				cout << x << " ";
			}
			cout << "\n";
			*/

			index[i] = 0;  // backtracking here
		}
	}	
}

void permutation(string st, int level){

	if(level == st.length()-1){
		cout << st << "\n";
	}

	for(int i = level ; i < st.length(); i++){
		//string st_tmp= st;			
		//swap(st_tmp[level],st_tmp[i]);
		//permutation(st_tmp, level+1);
		swap(st[level],st[i]);
		permutation(st, level+1);
		swap(st[level],st[i]);
	}
}

int main(){

	string st = "abc";

	int n = st.size();
	vector<int> index(n,0);
	vector<char>result(n);

	//string_permutation(st,0,result,index);	
	//
	permutation(st, 0);

	return 0;
}
