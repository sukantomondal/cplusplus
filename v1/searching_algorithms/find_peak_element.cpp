/*Find a peak element
Given an array of integers. Find a peak element in it. An array element is peak if it is NOT smaller than its neighbors. For corner elements, we need to consider only one neighbor. For example, for input array {5, 10, 20, 15}, 20 is the only peak element. For input array {10, 20, 15, 2, 23, 90, 67}, there are two peak elements: 20 and 90. Note that we need to return any one peak element.

Following corner cases give better idea about the problem.
1) If input array is sorted in strictly increasing order, the last element is always a peak element. For example, 50 is peak element in {10, 20, 30, 40, 50}.
2) If input array is sorted in strictly decreasing order, the first element is always a peak element. 100 is the peak element in {100, 80, 60, 50, 20}.
3) If all elements of input array are same, every element is a peak element.
*/


#include<iostream>
#include<vector>
using namespace std;


int find_peak_element(vector<int> arr, int l,int r){

	int n= arr.size();

	if(l<0 && r > n-1)
		return -1;

	int mid = (l+r)/2;

	if(mid == 0 || mid == n-1)
		return arr[mid];

	if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
		return arr[mid];


	if(arr[mid] < arr[mid-1])
		return find_peak_element(arr,l,mid-1);
	else
		return find_peak_element(arr,mid+1,r);
}

int main(){
	vector<int> arr = {10, 1, 1, 1, 1, 5};
	cout << find_peak_element(arr, 0, arr.size()-1);
	return 0;
}

