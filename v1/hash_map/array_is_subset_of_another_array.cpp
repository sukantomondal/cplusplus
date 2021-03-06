/*Find whether an array is subset of another array | Added Method 3
Given two arrays: arr1[0..m-1] and arr2[0..n-1]. Find whether arr2[] is a subset of arr1[] or not. Both the arrays are not in sorted order. It may be assumed that elements in both array are distinct.
Examples:

Input: arr1[] = {11, 1, 13, 21, 3, 7}, arr2[] = {11, 3, 7, 1}
Output: arr2[] is a subset of arr1[]

Input: arr1[] = {1, 2, 3, 4, 5, 6}, arr2[] = {1, 2, 4}
Output: arr2[] is a subset of arr1[]

Input: arr1[] = {10, 5, 2, 23, 19}, arr2[] = {19, 5, 3}
Output: arr2[] is not a subset of arr1[]
*/


#include<iostream>
#include<set>
#include<vector>
using namespace std;


bool is_subset(vector<int> arr1, vector<int> arr2){

	set<int> hash_table;
	for(int x : arr1){
		hash_table.insert(x);
	}
	for(int x : arr2){
		if(hash_table.find(x) == hash_table.end()){
			return false;
		}
	}
	return true;
}

int main(){
	
	vector<int> arr1 = {11, 1, 13, 21, 3, 7};
	vector<int> arr2 = {11, 3, 7, 1};
	cout << is_subset(arr1,arr2) << "\n";
	return 0;
}


