/*URLify a given string (Replace spaces is %20)
Write a method to replace all the spaces in a string with ‘%20’. You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the “true” length of the string.

Examples:

Input : "Mr John Smith", 13
Output : Mr%20John%20Smith

Input : "Mr John Smith   ", 13
Output : Mr%20John%20Smith
*/

#include<iostream>
#include<string>
using namespace std;

string urlify(string s){

	int i = s.length();
	int count = 0;
	while(s[i-1] == ' '){
		count++;
		i--;
	}

	s.erase(s.length()-count); // removing trailing spaces;

	i = 0;
	while(s[i]){
		if(s[i] == ' '){
			s.erase(i,1);
			s.insert(i,"%20");
		}
		i++;
	}
	return s;
}

int main(){

	string s = "Mr John Smith          ";

	cout << urlify(s);
	return 0;
}
