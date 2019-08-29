/*Longest Increasing Subsequence | DP-3
We have discussed Overlapping Subproblems and Optimal Substructure properties.

Let us discuss Longest Increasing Subsequence (LIS) problem as an example problem that can be solved using Dynamic Programming.
The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order. For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}.
longest-increasing-subsequence

More Examples:

Input  : arr[] = {3, 10, 2, 1, 20}
Output : Length of LIS = 3
The longest increasing subsequence is 3, 10, 20

Input  : arr[] = {3, 2}
Output : Length of LIS = 1
The longest increasing subsequences are {3} and {2}

Input : arr[] = {50, 3, 10, 7, 40, 80}
Output : Length of LIS = 4
The longest increasing subsequence is {3, 7, 40, 80}
Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
*/


#include<iostream>
#include<vector>
using namespace std;

int longest_increasing_subsequence(vector<int> arr){

	vector<int> lis(arr.size(),1);

	int max_len = 0;

	for(int i = 0 ; i < arr.size(); i++){

		for(int j = 0; j < i; j++){

			if(arr[j] < arr[i]){
				lis[i]= max(lis[i],lis[j]+1);
			}
		}

		max_len= max(max_len,lis[i]);
	}

	return max_len;
}

int main(){


	vector<int> arr = {50, 3, 10, 7, 40, 80};


	cout << longest_increasing_subsequence(arr);

	return 0;
}
