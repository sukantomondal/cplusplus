/*Given a string, find its first non-repeating character
Given a string, find the first non-repeating character in it. For example, if the input string is “GeeksforGeeks”, then output should be ‘f’ and if input string is “GeeksQuiz”, then output should be ‘G’.
*/

#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;


char non_repeat_char(string s){

	unordered_map<char, int> map;

	for(int i = 0 ; s[i]; i++){
		map[s[i]]++;
	}

	for(int i = 0 ; s[i]; i++){

		if(map[s[i]] == 1)
			return s[i];
	}

	return '#';
}


int main(){

	string s = "GeeksforGeeks";

	cout << non_repeat_char(s) << "\n";
	return 0;
}
