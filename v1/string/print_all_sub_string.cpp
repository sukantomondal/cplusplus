/* print all sub-strings */


#include<iostream>
using namespace std;

void print_sub_sequence(string s, int level , string sub_str){
	if(s.length()== level){
		cout << sub_str << "\n";
		return;
	}
	print_sub_sequence(s,level+1,sub_str+s[level]);
	print_sub_sequence(s,level+1,sub_str);	
}

void print_sub_strings(string s){

	for(int i = 0 ; i < s.length(); i++){
		for(int j = i ; j < s.length(); j++){
			string sub_str = s.substr(i, j-i+1);
			cout << sub_str << "\n";
		}
	}
}


int main(){
	string s = "abc";
	print_sub_sequence(s,0,"");
	print_sub_strings(s);
	return 0;
}
