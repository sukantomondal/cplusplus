#include<iostream>
#include<vector>
using namespace std;

/*
Given a sorted and rotated array, find if there is a pair with a given sum
Given an array that is sorted and then rotated around an unknown point. Find if the array has a pair with a given sum ‘x’. It may be assumed that all elements in the array are distinct.
Examples :

Input: arr[] = {11, 15, 6, 8, 9, 10}, x = 16
Output: true
There is a pair (6, 10) with sum 16

Input: arr[] = {11, 15, 26, 38, 9, 10}, x = 35
Output: true
There is a pair (26, 9) with sum 35

Input: arr[] = {11, 15, 26, 38, 9, 10}, x = 45
Output: false
There is no pair with sum 45.
*/


bool find_pair_sum(vector<int> arr, int sum){

	int n = arr.size();
	int l,r;
	for (int i=0; i<n-1; i++){
		if(arr[i]> arr[i+1]){

			l = (i+1)%n;  // finding the pivot
			r = i;
		}
	}

	while (l!=r){


		if(arr[l]+arr[r] == sum)
			return true;
		
		if(arr[l]+arr[r] < sum){
			l = (l+1) % n;
		}
		else{
			r = (n+r-1) % n;
		}
	
	}

	return false;

}

int main(){
	vector <int> arr = {11,15,6,8,9,10};

	int sum = 16;
	if(find_pair_sum(arr,sum)){

		cout << "The pair of sum found\n";
	}
	else{
		cout << "The pair some not found\n";
	}

	return 0;
}

