/*Move all zeroes to end of array
Given an array of random numbers, Push all the zero’s of a given array to the end of the array. For example, if the given arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 9, 8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be same. Expected time complexity is O(n) and extra space is O(1).

Example:

Input :  arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
Output : arr[] = {1, 2, 4, 3, 5, 0, 0,0};

Input : arr[]  = {1, 2, 0, 0, 0, 3, 6};
Output : arr[] = {1, 2, 3, 6, 0, 0, 0};

*/


#include<iostream>
#include<vector>
using namespace std;

void move(vector<int> &arr){

	int l = 0 , r = arr.size()-1;

	while(l<=r){

		if(arr[l] == 0 && arr[r] >0){
			swap(arr[l], arr[r]);
		}else if(arr[l]>0){
			l++;
		}else if(arr[r] == 0){
			r--;
		}
	}
}


void print(vector<int> arr){

	for(auto x : arr){
		cout << x << " ";
	}
	cout << "\n";
}


int main(){

	//vector<int> arr = {1, 2, 0, 0, 0, 3, 6};
	vector<int> arr = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};

	print(arr);
	move(arr);
	print(arr);

	return 0;
}


