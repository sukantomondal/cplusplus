/*Perfect Sum Problem (Print all subsets with given sum)
Given an array of integers and a sum, the task is to print all subsets of given array with sum equal to given sum.

Examples:

Input : arr[] = {2, 3, 5, 6, 8, 10}
        sum = 10
Output : 5 2 3
         2 8
         10

Input : arr[] = {1, 2, 3, 4, 5}
        sum = 10
Output : 4 3 2 1 
         5 3 2 
         5 4 1 
	 */

#include<iostream>
#include<vector>
#include<map>
using namespace std;



void perfect_sum(vector<int> arr, int sum){

	vector<pair<int, int>> sub_arrays;

	map<int , int> map;
	int curr_sum = 0;
	for(int i = 0 ; i < arr.size(); i++){
		curr_sum += arr[i];
		map[curr_sum] = i;

		if(curr_sum == sum){
			sub_arrays.push_back({0,i});
		}

		if(map.find(curr_sum - sum) != map.end()){
			sub_arrays.push_back({map[curr_sum - sum]+1, i});
		}
	}


	for(auto x : sub_arrays){

		for(int i = x.first ; i <=x.second; i++){

			cout << arr[i] << " ";
		}

		cout << "\n";
	}
}

int main(){

	vector<int> arr = {2, 3, 5, 6, 8, 10};

	perfect_sum(arr, 10);
	return 0;
}
