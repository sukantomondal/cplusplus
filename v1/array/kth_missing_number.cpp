/*k-th missing element in an unsorted array
Given an unsorted sequence a[], the task is to find the K-th missing contiguous element in the increasing sequence of the array elements i.e. consider the array in sorted order and find the kth missing number. If no k-th missing element is there output -1.

Note: Only elements exists in the range of minimum and maximum element to be considered.
Examples:

Input: arr[] = {2, 4, 10, 7}, k = 5
Output: 9
Missing elements in the given array: 3, 5, 6, 8, 9
5th missing is 9.

Input: arr[] = {1, 3, 4}, k = 5
Output: -1
*/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;


int find_kth_missing_number(vector<int> arr,int missing_number_index){

	unordered_set<int> numbers;

	int max = *max_element(arr.begin(),arr.end());
	int min = *min_element(arr.begin(),arr.end());

	for(int x: arr){
		numbers.insert(x);
	}

	int k = 0;

	for(int i= min ; i <= max; i++){

		if(numbers.find(i) == numbers.end()){
			k++; // mising number found
		}

		if(k== missing_number_index){
			return i;
		}
	}

	return -1;
}

int main(){


	vector<int> arr = { 2, 4, 10, 7 };
	cout << find_kth_missing_number(arr, 5) << "\n";
	return 0;
}
