/*Count all possible paths from top left to bottom right of a mXn matrix
The problem is to count all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down

Examples :

Input :  m = 2, n = 2;
Output : 2
There are two paths
(0, 0) -> (0, 1) -> (1, 1)
(0, 0) -> (1, 0) -> (1, 1)

Input :  m = 2, n = 3;
Output : 3
There are three paths
(0, 0) -> (0, 1) -> (0, 2) -> (1, 2)
(0, 0) -> (0, 1) -> (1, 1) -> (1, 2)
(0, 0) -> (1, 0) -> (1, 1) -> (1, 2)

*/

#include<iostream>
#include<vector>
using namespace std;




int number_of_path(int n, int m){

	vector<vector<int>>dp(n, vector<int>(m));

	for(int i = 0 ; i < m ; i++){
		dp[0][i] = 1;
	}

	for(int i = 0 ; i < n; i++ ){
		dp[i][0] = 1;
	}

	for(int i = 1; i < n ; i++){

		for(int j = 1 ; j < m ; j++){
			dp[i][j] = dp[i-1][j] + dp[j-1][i]; // dp[i-1][j-1];
		}
	}

	return dp[n-1][m-1];
}

int main(){


	cout << number_of_path(2,3) << "\n";
	return 0;
}
