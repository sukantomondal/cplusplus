/* Author : Sukanto Mondal */

/*
 * Kadane’s Algorithm, aka Maximum Sum of Subarray, is an interesting algorithm problem that can be solved with different approaches. This problem is a nice and intuitive question to learn more about Dynamic Programming.
 */


#include<iostream>
#include<vector>
using namespace std;

int max_sum_subarray(vector<int>arr){
	
	int max_so_far = INT32_MIN;
	int curr_max = arr[0];

	int start =0, end = 0, s=0;

	for(int i=1; i < arr.size(); i++){
		if(arr[i] > curr_max+arr[i])
			s=i;
		curr_max = max(arr[i],curr_max+arr[i]);
		if(max_so_far < curr_max){
			max_so_far= curr_max;
			start = s;
			end = i;
		}
	}

	cout <<"Start " << start << " end " << end << "\n";

	int sum = 0;

	for(int i = start; i<=end ; i++){
		cout << arr[i] << " ";
		sum+=arr[i];
	}
	cout<< "\nThe sum is " << sum << "\n";

	return max_so_far;
}


int main(){

	vector<int> arr = {-2,-3,4,-1,-1,1,5};
	cout << "Max subsequent sum : " << max_sum_subarray(arr);
	return 0;

}
