/*Given two arrays count all pairs whose sum is an odd number
Given two arrays of N and M integers. The task is to find the number of unordered pairs formed of elements from both arrays in such a way that their sum is an odd number.

Note: An element can only be one pair.

Examples:

Input: a[] = {9, 14, 6, 2, 11}, b[] = {8, 4, 7, 20}
Output: 3
{9, 20}, {14, 7} and {11, 8}

Input: a[] = {2, 4, 6}, b[] = {8, 10, 12}
Output: 0

Approach: Count the number of odd and even numbers in both the arrays and the answer to the number of pairs will be min(odd1, even2) + min(odd2, even1), because odd + even is only odd.

*/


#include<iostream>
#include<vector>
using namespace std;

void count_pair(vector<int> arr1, vector<int> arr2){
	

	int odd1 = 0 , even1 = 0 , odd2 = 0, even2 =0;
	
	for(int x : arr1){
		if(x%2!=0)
			odd1++;
		else
			even1++;
	}

	for(int x : arr2){
		if(x%2!=0)
			odd2++;
		else
			even2++;
	}

	int count = min(odd1,even2) + min(odd2, even1);

	cout << count;
}

int main(){

	vector<int> arr1 = {9, 14, 6, 2, 11};
	vector<int> arr2 = {8, 4, 7, 20};

	count_pair(arr1,arr2);

	return 0;
}
