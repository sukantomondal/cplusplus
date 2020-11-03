/*Remove spaces from a given string
Given a string, remove all spaces from the string and return it.

Input:  "g  eeks   for ge  eeks  "
Output: "geeksforgeeks"
Expected time complexity is O(n) and only one traversal of string.
*/

#include<iostream>
#include<string>
using namespace std;

string remove_space(string s){

	int count = 0;
	for(int i = 0 ; s[i]; i++){
		if(s[i] != ' ')
			s[count++] = s[i];
	}
	//s[count] = '\0';
	s.erase(count);
	return s;
}

int main(){
	string s = "g  eeks   for ge  eeks  ";
	cout << remove_space(s);
	return 0;
}
