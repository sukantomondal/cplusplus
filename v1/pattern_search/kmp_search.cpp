/*Kmp patterent search algorithm */


#include<iostream>
#include<vector>
using namespace std;


void make_lsp(vector<int> &lsp, string pat){

	int n = pat.length();

	int len = 0, i = 1;
	lsp[0] = 0;

	while (i < n){

		if(pat[len] == pat[i]){
			len++;
			lsp[i] = len;
			i++;
		}else{

			if(len!=0){
				len = lsp[len-1];
			}
			else{
				lsp[i]=0;
				i++;
			}
		}
	}
}


void search_pattern(string txt, string pat, vector<int> lsp){

	int i = 0 , j = 0;

	int m = txt.length();
	int n = pat.length();

	while (i<m){

		if(txt[i]==pat[j]){
			i++;
			j++;
		}
		
		if(j == n){
			cout << "pattern found at " << i-j << "\n";
		       	j = lsp[j-1];	
		}
		
		else if(i < m && txt[i] != pat[j]){
			if(j!=0){
				j= lsp[j-1];
			}else{
				i++;
			}
		}
	}
}

int main(){

	string pat = "ABABCABAB";
	string txt = "ABABDABACDABABCABAB";
	vector<int> lsp(pat.length(),0);

	for(int x : lsp){

		cout << x << " ";
	}
	cout << "\n";


	make_lsp(lsp,pat);
	for(int x : lsp){

		cout << x << " ";
	}
	cout << "\n";
	search_pattern(txt,pat,lsp);
	return 0;
}
