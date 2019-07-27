/*
Maximum sum combination from two arrays
Given two arrays arr1[] and arr2[] each of size N. The task is to choose some elements from both the arrays such that no two elements have the same index and no two consecutive numbers can be selected from a single array. Find the maximum sum possible of above-chosen numbers.

Examples:

Input : arr1[] = {9, 3, 5, 7, 3}, arr2[] = {5, 8, 1, 4, 5}
Output : 29
Select first, third and fivth element from the first array.
Select the second and fourth element from the second array.

Input : arr1[] = {1, 2, 9}, arr2[] = {10, 1, 1}
Output : 19
Select last element from the first array and first element from the second array.


Approach :
This problem is based on dynamic programming.

Let dp(i, 1) be the maximum sum of the newly selected elements if the last element was taken from the position(i-1, 1).
dp(i, 2) is the same but the last element taken has the position (i-1, 2)
dp(i, 3) the same but we didn’t take any element from position i-1
.

Recursion realtions are :

dp(i, 1)=max(dp (i – 1, 2) + arr(i, 1), dp(i – 1, 3) + arr(i, 1), arr(i, 1) );
dp(i, 2)=max(dp(i – 1, 1) + arr(i, 2 ), dp(i – 1, 3) + arr (i, 2), arr(i, 2));
dp(i, 3)=max(dp(i- 1, 1), dp( i-1, 2) ).

We don’t actually need dp( i, 3), if we update dp(i, 1) as max(dp(i, 1), dp(i-1, 1)) and dp(i, 2) as max(dp(i, 2), dp(i-1, 2)).

Thus, dp(i, j) is the maximum total sum of the elements that are selected if the last element was taken from the position (i-1, 1) or less. The same with dp(i, 2). Therefore the answer to the above problem is max(dp(n, 1), dp(n, 2)).
*/

#include<iostream>
#include<vector>
using namespace std;

void maximum_sum(vector<int> arr1, vector<int> arr2){

	vector<vector<int>> dp (arr1.size(),vector<int>(2));

	for(int i = 0 ; i< arr1.size(); i++){

		if(i==0){
			dp[i][0] = arr1[i];
			dp[i][1] = arr2[i];
			continue;
		}

		dp[i][0] = max(dp[i-1][0], dp[i-1][1] + arr1[i]);
		dp[i][1] = max(dp[i-1][1], dp[i-1][0] + arr2[i]);

		//cout << dp[i][0] <<"  "<< dp[i][1] << "\n";
	}

	cout << max (dp[arr1.size()-1][0], dp[arr1.size()-1][1]);
}

int main(){


	vector<int> arr1 = {9, 3, 5, 7, 3};
	vector<int> arr2 = {5, 8, 1, 4, 5};
	maximum_sum(arr1,arr2);
	return 0;
}

