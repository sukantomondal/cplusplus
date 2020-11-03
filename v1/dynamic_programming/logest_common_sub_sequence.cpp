/* Longest common sub string */

#include<iostream>
#include<vector>
using namespace std;


void longest_common_sub_sequence(string s1 , string s2){

	vector<vector<int>> dp (s1.length()+1,vector<int>(s2.length()+1,0));

	for(int i = 1 ; i <= s1.length(); i++){
		for(int j= 1; j <= s2.length(); j++){

			if(s1[i-1]==s2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else
			{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	cout << dp[s1.length()][s2.length()] << "\n";


	for(auto x: dp){
		for(auto y :x)
			cout<< y;

		cout << "\n";
	}

	cout << "logeest sequence\n";


	string s;

	int row = s1.length();
	int col = s2.length();

	while (row >= 0 && col>= 0){

		if(row-1>=0 && col-1 >= 0){
			if(s1[row-1] == s2[col-1]){
				string st;
				st.append(1,s2[col-1]);
				s = st.append(s);
				row --;
				col --;
			}
			else if(dp[row-1][col] > dp[row][col-1]){
				row --;
			}else{
				col --;
			}
		}else if(row-1>=0){
			row --;
		}else{
			col--;
		}
	}

	cout << s;


}

int main(){

	string s1 = "AGGTAB";
	string s2 = "GXTXAYB";

	longest_common_sub_sequence(s1,s2);

	return 0;
}
