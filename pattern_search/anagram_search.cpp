/*Anagram Substring Search (Or Search for all permutations)
Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] and its permutations (or anagrams) in txt[]. You may assume that n > m. 
Expected time complexity is O(n)

Examples:

1) Input:  txt[] = "BACDGABCDA"  pat[] = "ABCD"
   Output:   Found at Index 0
             Found at Index 5
             Found at Index 6
2) Input: txt[] =  "AAABABAA" pat[] = "AABA"
   Output:   Found at Index 0
             Found at Index 1
             Found at Index 4

	     */

#include <iostream>
#include <vector>
using namespace std;


int string_sum (string str){

	int str_sum =0;
	for (char c : str){
		str_sum += c;
	}
	return str_sum;
}
void search(string txt, string pat){

	int m = txt.length();
	int n = pat.length();

	int pat_sum = string_sum (pat);

	for (int i = 0 ; i<= m-n ; i++){
		int sub_txt_sum = string_sum(txt.substr(i,n));

		if (sub_txt_sum == pat_sum){
			cout << "Anagram found at " << i << "\n";
		}
	}
}


int main(){

	string txt = "BACDGABCDA";
	string pat = "ABCD";
	search(txt,pat);
}
