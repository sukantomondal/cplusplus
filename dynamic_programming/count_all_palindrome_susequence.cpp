/*Count All Palindromic Subsequence in a given String
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
Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
The above problem can be recursively defined.

Initial Values : i= 0, j= n-1;

CountPS(i,j)
// Every single character of a string is a palindrome 
// subsequence 
if i == j
   return 1 // palindrome of length 1

// If first and last characters are same, then we 
// consider it as palindrome subsequence and check
// for the rest subsequence (i+1, j), (i, j-1)
Else if (str[i] == str[j)]
   return   countPS(i+1, j) + countPS(i, j-1) + 1;

else
   // check for rest sub-sequence and  remove common
   // palindromic subsequences as they are counted
   // twice when we do countPS(i+1, j) + countPS(i,j-1)
   return countPS(i+1, j) + countPS(i, j-1) - countPS(i+1, j-1) 

*/



#include<iostream>
#include<vector>
using namespace std;

int count_ps(string s){

	vector<vector<int>> dp(s.length(), vector<int>(s.length(),0));

	for(int i = 0 ; i < s.length(); i++){
		dp[i][i] = 1;
	}

	for(int l= 2; l <= s.length() ; l++){
		for(int i = 0 ; i< s.length(); i++){

			int k = i+l-1; // last element index

			if(k>=s.length())
				continue;
			cout << i << " "<< k << "\n";

			if(s[i] == s[k]){
				dp[i][k] = dp[i+1][k] + dp[i][k-1] +1;
			}else{
				dp[i][k] = dp[i+1][k] + dp[i][k-1] - dp[i+1][k-1];
			}
			
		}
	}

	return dp[0][s.length()-1];
}


int main(){

	string s = "aaaa";
	cout << count_ps(s);

	return 0;
}

