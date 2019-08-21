/*Largest subarray with equal number of 0s and 1s
Given an array containing only 0s and 1s, find the largest subarray which contain equal no of 0s and 1s. Expected time complexity is O(n).
Examples:

Input: arr[] = {1, 0, 1, 1, 1, 0, 0}
Output: 1 to 6 (Starting and Ending indexes of output subarray)

Input: arr[] = {1, 1, 1, 1}
Output: No such subarray

Input: arr[] = {0, 0, 1, 1, 0}
Output: 0 to 3 Or 1 to 4

*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int lse(vector<int> arr){

	unordered_map<int, int> map;
	int max_len = -1;
	int sum=0;

	for(int i = 0 ; i < arr.size(); i++){

		if(arr[i] == 0){
			sum = sum-1; 
		}else{
			sum = sum+1;
		}

		if(sum == 0){
			max_len = max (i+1, max_len);
			cout << max_len << "\n";
		}else{
			auto it = map.find(sum);
			if(it != map.end()){
				cout << i << " " << it->second << "\n";
				max_len = max (max_len, i-it->second+1-1); 
			}else{
				map[sum] = i;
			}
		}

	}

	return max_len;
}

int main(){

	vector<int> arr1 = {0, 0, 1, 1, 0};
	//vector<int> arr1 = {1, 0, 1, 1, 1, 0, 0};
	cout << lse(arr1);
	return 0;
}

