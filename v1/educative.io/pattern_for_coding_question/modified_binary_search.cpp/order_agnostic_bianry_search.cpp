/*Approach 1: Order-Agnostic Binary Search
Problem statement
Given a sorted array of numbers, find out if a given number key is present in the array.
Though we know that the array is sorted, we don’t know if it’s sorted in ascending or descending order. You should assume that the array can have duplicates.
Write a function to return the index of the key if it is present in the array, otherwise return -1.
Example-1: Input: [1, 2, 3, 4, 5, 6, 7], key = 5, Output: 4
Example-2: Input: [10, 6, 4], key = 10, Output: 0
*/


#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> arr, int key){

	int start = 0;
	int end = arr.size()-1;

	bool is_asending = false;
	if(arr[start] < arr[end]){
		is_asending = true;
	}

	while(start <= end){
		int mid = start + (end-start)/2;
		
		if(arr[mid] == key)
			return mid;

		if(is_asending){
			if(arr[mid] < key){
				start = mid +1;
				//cout<< "hh\n";
			}else{
				end = mid-1;
			}
		}else{

			if(arr[mid] < key){
				end = mid-1;
			}else{
				start = mid+1;
			}
		}
	}

	return -1;
}

int main(){

	//vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
	vector<int> arr = {10, 6, 4};

	cout << search(arr,10);

	return 0;
}
