/*Find the length of largest subarray with 0 sum
Given an array of integers, find the length of the longest subarray with sum equals to 0.
Examples :

Input: arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
Output: 5
The largest subarray with 0 sum is -2, 2, -8, 1, 7

Input: arr[] = {1, 2, 3}
Output: 0
There is no subarray with 0 sum

Input: arr[] = {1, 0, 3}
Output: 1

*/


#include<iostream>
#include<vector>
#include<map>
using namespace std;




int max_length_sub_array(vector<int> arr){

	int max_len = 0;
	int sum = 0;

	map<int,int> hash_table;

	for(int i = 0 ; i< arr.size(); i++){

		sum +=arr[i];

		if(arr[i] == 0 && max_len == 0)
			max_len = 1;
		else if(sum == 0){
			max_len = i+1;
		}

		if(hash_table.find(sum) != hash_table.end()){
		
			if(max_len < i - hash_table[sum]){
				cout << hash_table[sum] + 1 << " "<< i << "\n";
			}
			max_len = max(max_len, i - hash_table[sum]);
		}
		else{
			hash_table[sum] = i;
		}
	}

	return max_len;
}


int main(){

	vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};

	cout << max_length_sub_array(arr) << "\n";

	return 0;
}
