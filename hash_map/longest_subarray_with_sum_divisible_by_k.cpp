/*Given an arr[] containing n integers and a positive integer k. The problem is to find the length of the longest subarray with sum of the elements divisible by the given value k.

Examples:

Input : arr[] = {2, 7, 6, 1, 4, 5}, k = 3
Output : 4
The subarray is {7, 6, 1, 4} with sum 18,
which is divisible by 3.

Input : arr[] = {-2, 2, -5, 12, -11, -1, 7}
Output : 5
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int longest_subarray(vector<int> arr, int k){

	int curr_sum = 0;
	int max_len=0;
	unordered_map<int, int> map;

	for(int i = 0 ; i < arr.size(); i++){

		curr_sum +=arr[i];
		if(curr_sum%k == 0){

			if(max_len < i+1){
				max_len = i+1;
			}
		}else if(map.find(curr_sum % k) == map.end()){
			map[curr_sum % k] = i;
		}else{

			if(max_len < i- map[curr_sum%k])
				max_len = i - map[curr_sum % k];
		}

		
	}

	return max_len;
}

int main(){

	//cout << -2%3;
	//
//	vector<int> arr = {2, 7, 6, 1, 4, 5};

	vector<int> arr = {-2, 2, -5, 12, -11, -1, 7};

	cout << longest_subarray(arr,3);

	return 0;
}
