/*Smallest Subarray with a given sum (easy)
 * find sub array with given sum
*/


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int smallest_subarr(vector<int> arr, int sum){

	int curr_sum = 0;
	int min_len = INT8_MAX;
	unordered_map<int, int> map;
	for(int i = 0 ; i < arr.size(); i++){
		curr_sum+= arr[i];
		if(curr_sum == sum){
			int len = i+1;
			min_len = min(min_len, len);
		}

		if(map.find(curr_sum - sum) != map.end()){
			int len = i- map[curr_sum -sum];
			min_len = min(len,min_len);
		}

		map[curr_sum] = i;

	}

	return min_len;
}

int main(){

	vector<int> arr = {1, 4, 32,1,20, 3, 10, 5};
	cout << smallest_subarr(arr, 33);
	return 0;


}
