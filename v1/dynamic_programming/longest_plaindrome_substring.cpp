/* logest common plaindrom sub string */

#include<iostream>
#include<vector>
using namespace std;



bool is_plaindrom(string s , int start, int end){

	while (start<end){
		if(s[start] != s[end])
			return false;
		start++;
		end--;
	}
	return true;
}

// recursion
//
int lcps(string s, int i, int j){
	
	if(i>j)
		return 0;
	if(i==j){
		return 1;
	}
	if(is_plaindrom(s,i,j)){
		return j-i+1;
	}
	else{
		return max(lcps(s,i,j-1),lcps(s,i+1,j));
	}
}

//using dp
//
void lcps_dp(string s){
	vector<vector<int>> dp (s.length(),vector<int>(s.length(),0));
	
	for(int i = 0; i < s.length(); i++){
		dp[i][i] = 1;
	}
	for(int l = 2; l <= s.length(); l++ ){
		for(int i = 0 ; i <= s.length() - l; i++){
			int j = i+l-1;
			if(is_plaindrom(s,i,j)){
				dp[i][j] = j-i+1;
			}else{
				dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
			}
		}
	}

	cout << dp[0][s.length()-1] << "\n";
}



// another dp

void lcps_another_dp(string s){

	vector<vector<int>> dp (s.length(),vector<int>(s.length(),0));

	int max_len = 1;
	for(int i = 0; i < s.length(); i++){
		dp[i][i] = 1;
	}

	for(int i = 0 ; i < s.length(); i++){
		if(s[i] == s[i+1]){
			dp[i][i+1]=1;
			max_len = 2;
		}
	}

	for(int l = 2; l <= s.length(); l++ ){
		for(int i = 0 ; i <= s.length() - l; i++){
			int j = i+l-1;
			if(s[i] == s[j] && dp[i+1][j-1]){
				dp[i][j] = 1;
				if(max_len < l){
					max_len = l;
				}
			}
		}
	}

	cout << max_len << "\n";
}

int main(){
	string s = "geeks";

	cout << lcps(s,0,s.length()-1) << "\n";

	lcps_dp(s);

	lcps_another_dp(s);

	return 0;
}
