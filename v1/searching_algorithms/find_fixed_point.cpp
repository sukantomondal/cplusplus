/*Find a Fixed Point (Value equal to index) in a given array
Given an array of n distinct integers sorted in ascending order, write a function that returns a Fixed Point in the array, if there is any Fixed Point present in array, else returns -1. Fixed Point in an array is an index i such that arr[i] is equal to i. Note that integers in array can be negative.

Examples:

  Input: arr[] = {-10, -5, 0, 3, 7}
  Output: 3  // arr[3] == 3 

  Input: arr[] = {0, 2, 5, 8, 17}
  Output: 0  // arr[0] == 0 


  Input: arr[] = {-10, -5, 3, 4, 7, 9}
  Output: -1  // No Fixed Point

  */


#include <iostream>
#include <vector>
using namespace std;

int find_fixed_point(vector<int> arr, int l, int r){

	if(l>r)
		return -1;

	if (l==r && arr[l] == l)
		return l;

	int mid = (l+r)/2;

	if(arr[mid] == mid)
		return mid;

	if(arr[mid] > mid)
		return find_fixed_point(arr, l,mid-1);
	else 
		return find_fixed_point(arr,mid+1,r);

}

int main(){

	vector<int> arr = {-10,-5,0,3,7};
	cout << find_fixed_point(arr,0,arr.size()-1);
	return 0;

}
