/*Print all permutations with repetition of characters
Given a string of length n, print all permutation of the given string. Repetition of characters is allowed. Print these permutations in lexicographically sorted order 
Examples:

Input: AB
Ouput: All permutations of AB with repetition are:
      AA
      AB
      BA
      BB

Input: ABC
Output: All permutations of ABC with repetition are:
       AAA
       AAB
       AAC
       ABA
       ...
       ...
       CCB
       CCC
       */

#include<iostream>
#include<string>
#include<vector>

using namespace std;



void print_permutation(string s, char a, vector<char> res){

	if(res.size() == s.length()){
		for(auto x : res){
			cout << x;
		}
		cout << "\n";
		return;
	}

	for(int i = 0 ;  i < s.length(); i++){
		res.push_back(s[i]);
		print_permutation(s,s[i],res);
		res.pop_back();
	}
}


int main(){

	string s= "ABC";
	vector<char> res;
	print_permutation(s, s[0], res);
	return 0;
}
