/*https://www.geeksforgeeks.org/count-palindromic-subsequence-given-string/
 *
 * Count All Palindromic Subsequence in a given String
Find how many palindromic subsequence (need not necessarily be distinct) can be formed in a given string. Note that the empty string is not considered as a palindrome.
Examples:

Input : str = "abcd"
Output : 4
Explanation :- palindromic  subsequence are : "a" ,"b", "c" ,"d"

Input : str = "aab"
Output : 4
Explanation :- palindromic subsequence are :"a", "a", "b", "aa"

Input : str = "aaaa"
Output : 15

*/


#include<iostream>
#include<vector>
using namespace std;

int count_ps(string s, int low , int high){

	if(low > high)
		return 0;

	if(low == high)
		return 1;

	if(s[low] == s[high]){

		return 1 + count_ps(s,low+1,high) + count_ps(s,low,high-1);
	}else{

		return count_ps(s,low+1,high) + count_ps(s,low,high-1) - count_ps(s, low+1,high-1);
	}
}

//since there many overlaping sub problem, the problem can be solved using dynamic programming*/



int main(){

	string s = "abcd";
	cout << count_ps(s, 0 , s.length()-1);
	return 0;
}
