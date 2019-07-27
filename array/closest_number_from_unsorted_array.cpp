/*Closest numbers from a list of unsorted integers
Given a list of distinct unsorted integers, find the pair of elements that have the smallest absolute difference between them? If there are multiple pairs, find them all.

Examples:

Input : arr[] = {10, 50, 12, 100}
Output : (10, 12)
The closest elements are 10 and 12

Input : arr[] = {5, 4, 3, 2}
Output : (2, 3), (3, 4), (4, 5)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void closest_number(vector<int> arr){

	vector<pair<int,int>> closest_elements;

	sort(arr.begin(),arr.end());
	int min_diff = INT8_MAX;

	for(int i = 1; i< arr.size(); i++){
		if(arr[i] - arr[i-1] < min_diff)
			min_diff= arr[i] - arr[i-1];
		
	}

	for(int i =1 ; i< arr.size(); i++){

		if(arr[i]-arr[i-1] == min_diff)
			cout << "( " << arr[i-1] << " , " << arr[i] << " ) ";
	}

	cout << "\n";

}

int main(){

	vector<int> arr = {5, 4, 3, 2};

	closest_number(arr);

	return 0;

}
