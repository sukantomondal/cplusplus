/* Longest common sub string */

#include<iostream>
#include<vector>
using namespace std;


void longest_common_sub_string(string s1 , string s2){

	vector<vector<int>> dp (s1.length()+1,vector<int>(s2.length()+1,0));

	int max_length = 0;
	for(int i = 1 ; i <= s1.length(); i++){
		for(int j= 1; j < s2.length(); j++){

			if(s1[i-1]==s2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
				if(dp[i][j] > max_length){
					max_length = dp[i][j];
				}
			}
		}
	}

	cout << max_length << "\n";
}

int main(){

	string s1 = "cvaddcc";
	string s2 = "cfaddpi";

	longest_common_sub_string(s1,s2);

	return 0;
}
