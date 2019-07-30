/*Given a string, the task is to count all palindrome substring in a given string. Length of palindrome substring is greater then or equal to 2.

Examples:
Input : str = "abaab"
Output: 3
Explanation : 
All palindrome substring are :
 "aba", "aa", "baab" 

Input : str = "abbaeae"
Output: 4
Explanation : 
All palindrome substring are : 
"bb", "abba", "aea", "eae":


https://www.geeksforgeeks.org/count-palindrome-sub-strings-string-set-2/

Initial Values : i = 0, j = n-1;
Given string 'str'

CountPS(i, j)
   
   // If length of string is 2 then we 
   // check both character are same or not 
   If (j == i+1)
      return str[i] == str[j]

   Else If str[i..j] is PALINDROME 
      // increment count by 1 and check for 
      // rest palindromic substring (i, j-1), (i+1, j)
      // remove common palindrome substring (i+1, j-1)
      return  countPS(i+1, j) + countPS(i, j-1) + 1 -
                                   countPS(i+1, j-1);

    Else // if NOT PALINDROME 
       // We check for rest palindromic substrings (i, j-1)
       // and (i+1, j)
       // remove common palindrome substring (i+1 , j-1)
       return  countPS(i+1, j) + countPS(i, j-1) - 
                             countPS(i+1 , j-1);

*/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;



bool is_plaindrom(string str, int l , int r){

	int len = r-l+1;

//	for(int i = l ; i <= r ; i++)
//		cout << str[i];

	if(len%2 == 0){
		int mid = len /2;
		for(int i = 0 ; i < mid ; i++){
			if(str[i] != str[r-i]){
				//cout << " false \n";
				return false;
			}
		}
	}
	else{
		int mid = len/2;
		
		for (int i = 0; i < mid ; i++){

			if(str[i] != str[r-i]){
				//cout << " false \n";
				return false;
			}
		}
	}

	//cout << " true \n";
	return true;
}

int countPS(string str, int l , int r){



	if(l>=r)
		return 0;

	if(r == l+1){    // if only two element involve
		if(str[l] == str[r]){
			return 1;
		}
		else{
			return 0;
		}
	}
	
	if(is_plaindrom(str,l,r)){
		return (countPS(str,l+1, r) + countPS(str,l,r-1) +1 - countPS(str,l+1,r-1));
	}
	else{
		return (countPS(str,l+1, r) + countPS(str,l,r-1) - countPS(str,l+1,r-1));
	}


}


void print(vector<vector<int>> dp){

	for (auto x : dp){

		for(auto y : x){

			cout << y << " ";
		}

		cout << "\n";
	}

	cout << "end \n";
}

// now using dynamic programming

int countPS_DP(string str){

	vector<vector<int>> dp(str.size(),vector<int>(str.size(),0));

	vector<vector<int>> p(str.size(),vector<int>(str.size(),false));

	for(int i = 0; i < str.size(); i++){
		dp[i][i] = 0;
		p[i][i] = true;
	}


	// for two length
	for(int i =0 ; i < str.size()-1; i++){

		if(str[i] == str[i+1]){
			dp[i][i+1] = 1;
			p[i][i+1] = true;
		}
	}


	for(int gap = 2 ; gap < str.size(); gap++){

		for (int i = 0 ; i < str.size()-gap; i++){

			int j = i+gap;

			if(str[i] == str[j] && p[i+1][j-1])
				p[i][j] = true;


			if(p[i][j]){

				dp[i][j] = dp[i+1][j] + dp[i][j-1] +1-dp[i+1][j-1];
			}else{
				dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
			}


		}
	}

	return dp[0][str.size()-1];
}


int main(){


        vector<pair<int,int>> p;

	string str = "abaab";

	cout << "recirsion : " <<countPS (str,0,str.length()-1) << "\n";

	cout << "DP : " << countPS_DP(str) << "\n";

	return 0;
}
