/* logest common plaindrome subsequence */

#include<iostream>
#include<vector>
using namespace std;


// recursion
//
int lcps(string s, int i, int j){

	if(i>j)
		return 0;

	if(i==j)
		return 1;

	if(s[i] == s[j]){
		return 2 + lcps(s,i+1,j-1);
	}
	else{
		return max(lcps(s,i,j-1), lcps(s,i+1,j));
	}
}



void print_dp(vector<vector<int>> dp){

	for(auto x : dp){

		for(auto y : x){
			cout << y << " ";
		}

		cout << "\n";
	}

	cout << "--\n";
}


// dynamic programing
//
 void dp_lcps(string s){
	 vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));

	 for(int i= 0; i < s.length(); i++){
		 dp[i][i] = 1; // base case;
	 }

	 for(int i = 0 ; i < s.length()-1; i++){  // base case
		 if(s[i]==s[i+1]){
			 dp[i][i+1] = 2; 
		 }else{
			 dp[i][i+1] = max(dp[i][i],dp[i+1][i+1]);
		 }
	 }

	 //print_dp(dp);

	 for(int l = 3 ; l <= s.length(); l++){
		 
		 for(int i = 0; i <= s.length()-l; i++){
			 int j =  i+l-1;
			 if(s[i] == s[j]){
				 dp[i][j] = 2 + dp[i+1][j-1];
			 }
			 else{
				 dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
			 } 
		 }

		 //print_dp(dp);	 	
	 }

	 print_dp(dp);

	 cout << dp[0][s.length()-1];
 }


int main(){

	string s = "GEEKS FOR GEEKS";
	cout << lcps(s, 0, s.length()-1) << "\n";

	dp_lcps(s);

	return 0;
}
