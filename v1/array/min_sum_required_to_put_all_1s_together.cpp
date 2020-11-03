/*Minimum Swaps required to group all 1’s together
Given an array of 0’s and 1’s, we need to write a program to find the minimum number of swaps required to group all 1’s present in the array together.

Examples:

Input : arr[] = {1, 0, 1, 0, 1}
Output : 1
Explanation: Only 1 swap is required to 
group all 1's together. Swapping index 1
and 4 will give arr[] = {1, 1, 1, 0, 0}

Input : arr[] = {1, 0, 1, 0, 1, 1}
Output : 1
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
A simple solution is to first count total number of 1’s in the array. Suppose this count is x, now we need to find the subarray of length x of this array with maximum number of 1’s. And minimum swaps required will be the number of 0’s in the subarray of length x with maximum number of 1’s.
Time Complexity: O(n2)

An efficient solution is to optimize the brute force technique of finding the subarray in above approach using the concept of sliding window technique. We can maintain a preCount array to find number of 1’s present in a subarray in O(1) time complexity.

*/

#include<iostream>
#include<vector>
using namespace std;


int count_min_swap(vector<int> arr){

	int x =0; // toatal number of 1s in array

	for(auto i : arr){
		if(i== 1)
			x++;
	}


	int max1s, count1s = 0;
	for(int i = 0 ; i < x; i++){
		if(arr[i] == 1)
			count1s++;

	}

	max1s = count1s; // max1s in a sliding window 

	for(int i = 1; i < arr.size()- x ; i++){

		if(arr[i-1] == 1)
			count1s--;

		if(arr[i+x-1] == 1) // traileing element
			count1s++;

		if(max1s < count1s)
			max1s = count1s;
	}

	int count0s = x-max1s;

	return count0s;
}

int main(){

	vector<int> arr = {1, 0, 1, 0, 1};

	cout << count_min_swap(arr) << "\n";
	return 0;
}
