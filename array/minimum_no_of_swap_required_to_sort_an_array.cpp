/*Minimum number of swaps required to sort an array | Set 2
Given an array of N distinct elements, find the minimum number of swaps required to sort the array.

Note: The problem is not asking to sort the array by the minimum number of swaps. The problem is to find the minimum swaps in which the array can be sorted.

Examples:

Input : arr[] = {4, 3, 2, 1}
Output : 2
Explanation : Swap index 0 with 3 and 1 with 2 to get the sorted array {1, 2, 3, 4}.

Input : arr[] = { 3, 5, 2, 4, 6, 8}
Output : 3

*/



#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int min_swap(vector<int> arr){
	
	vector<pair<int,int>> values;

	for(int i = 0; i< arr.size(); i++){
		values.push_back({arr[i],i});
	}

	sort(values.begin(),values.end());

	int ans = 0;

	for(int i = 0 ; i < values.size(); i++){

		if(values[i].second == i){
			continue;
		}else{

			swap(values[i].first, values[values[i].second].first);
			swap(values[i].second, values[values[i].second].second);
		}

		if(i!= values[i].second)
			i--;
		ans+=1;

	}

	return ans;

}

int main(){

	vector<int> arr = {4, 3, 2, 1};

	cout << min_swap(arr) << "\n";

	return 0;
}
