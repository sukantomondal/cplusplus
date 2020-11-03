/*Find an element in array such that sum of left array is equal to sum of right array
Given, an array of size n. Find an element which divides the array in two sub-arrays with equal sum.

Examples:

Input : 1 4 2 5
Output : 2
Explanation : If 2 is the partition, 
      subarrays are : {1, 4} and {5}

Input : 2 3 4 1 4 5
Output : 1
Explanation : If 1 is the partition, 
 Subarrays are : {2, 3, 4} and {4, 5}

 */

#include<iostream>
#include<vector>
using namespace std;


int find_partition_element(vector<int> arr){

	int n = arr.size();

	vector<int> prefix(n,0);
	vector<int> suffix(n);



	prefix[0] = arr[0];

	for(int i =1 ; i< n ; i++){
		prefix[i] = prefix[i-1]+arr[i]; 
	}

	suffix[0] = prefix[n-1];
	for(int j = 1; j< n ; j++){
		suffix[j] = suffix[j-1] - arr[j-1];
	}

	for(int k = 0; k < n ; k++){

		if(suffix[k] == prefix[k]){
			return k;
		}

	}

	return -1;
}


int find_partition_element_alt(vector<int> arr){

	int total_sum =0;

	for(int x : arr){
		total_sum +=x;
	}


	int sum_so_far = 0;

	for(int i = 0 ; i< arr.size() ; i++){
		total_sum -= arr[i];
		if(sum_so_far == total_sum){
			return i;
		}
		sum_so_far += arr[i];
	}

	return -1;
}


int main(){


	vector<int> arr = {1,4,2,5};

	for(int x: arr){
		cout << x << " ";
	}
	cout << "\n";

	cout <<"The partition element index is: " << find_partition_element(arr) << "\n";

	cout << "The partition element index is: " << find_partition_element_alt(arr) << "\n";
	return 0;
}
