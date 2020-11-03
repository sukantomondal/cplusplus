/*Sort an array without changing position of negative numbers
Given an array arr[] of N integers, the task is to sort the array without changing the position of negative numbers (if any) i.e. the negative numbers need not be sorted.

Examples:

Input: arr[] = {2, -6, -3, 8, 4, 1}
Output: 1 -6 -3 2 4 8

Input: arr[] = {-2, -6, -3, -8, 4, 1}
Output: -2 -6 -3 -8 1 4
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void sort_array(vector<int> arr){

	vector<int> ans;

	for(int x: arr){
		if(x >= 0)
			ans.push_back(x);
	}

	sort(ans.begin(),ans.end());

	int index = 0;
	for(int &x: arr){
		if(x>=0){
			x = ans[index++];
		}
	}

	cout << "Sorted  array : " ;
	for(int x : arr){

		cout << x << " " ;
	}
	cout << "\n";
}

int main(){

	vector<int> arr = {-2, -6, -3, -8, 4, 1};

	cout << "Given array: ";

	for(int x : arr){

		cout << x <<" ";
	}

	cout << "\n";
	sort_array(arr);

	return 0;
}
