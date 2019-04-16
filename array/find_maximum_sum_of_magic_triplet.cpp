/* Author : Sukanto Mondal */

/* Find maximum sum of triplets in an array such than i < j < k and a[i] < a[j] < a[k]
*/

/*Given an array of positive integers of size n. Find the maximum sum of triplet( ai + aj + ak ) such that 0 <= i < j < k < n and ai < aj < ak.

Input: a[] = 2 5 3 1 4 9
Output: 16

Explanation:
All possible triplets are:-
2 3 4 => sum = 9
2 5 9 => sum = 16
2 3 9 => sum = 14
3 4 9 => sum = 16
1 4 9 => sum = 14
Maximum sum = 16
*/


#include<iostream>
#include<vector>
using namespace std;

int find_max_sum(vector<int> nums){  // O(n^2) solution

	int right_max = -1; // max side of the numbers
	int left_max = -1; // min side of the numbers
	int max_sum = -1;

	for(int i=0; i< nums.size(); i++){

		left_max =-1; right_max=-1;

		for(int j=0; j<nums.size(); j++){   // max of minimum on left side

			if(i==j) continue;
			if(nums[j] < nums[i] && j<i){
				left_max = max(left_max,nums[j]);
			}
			if(nums[j] > nums[i] && j>i){
				right_max = max(right_max,nums[j]);
			}
		}

		if(left_max != -1 && right_max!=-1){
			max_sum = max(max_sum,(right_max+nums[i]+left_max));
		}
	}

	return max_sum;

}

/*int find_max_sum(vector<int> nums){ // O(n*nlogn) solution

	int size = nums.size();

	vector<int> smaller(size);
	vector<int> greater(size);

	int min_index = 0;
	int max_index = size-1;

	int min_max_val_index = 0;
	

	smaller[0] = -1;
	for(int i= 1; i< nums.size(); i++){

		if(nums[i] < nums[min_index]){
			min_index = i;
			smaller[i] = -1
		}
		else{
			smaller[i] = min_index;
			min_max_val_index = i;
		}

	}

}*/


int main(){

	vector<int> nums = {2,5,3,1,4,9};
	cout << find_max_sum(nums);
	return 0;
}
