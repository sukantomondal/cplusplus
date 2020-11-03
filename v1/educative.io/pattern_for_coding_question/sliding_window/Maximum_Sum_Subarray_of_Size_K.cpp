/*Maximum Sum Subarray of Size K (easy) */
/*Find maximum (or minimum) sum of a subarray of size k
Given an array of integers and a number k, find maximum sum of a subarray of size k.

Examples :

Input  : arr[] = {100, 200, 300, 400}
         k = 2
Output : 700

Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}
         k = 4
Output : 39
We get maximum sum by adding subarray {4, 2, 10, 23}
of size 4.

Input  : arr[] = {2, 3}
         k = 3
Output : Invalid
There is no subarray of size 3 as size of whole
array is 2.
*/

#include<iostream>
#include<vector>
using namespace std;

int find_max_sum(vector<int> arr, int k){

	if(arr.size()< k)
		return -1;
	
	// first window
	int max_sum=0;
	for(int i = 0 ; i < k; i++){
		max_sum += arr[i]; 
	}


	// sub sequent window
	//
	for(int i = 1 ; i < arr.size()-k+1; i++){
		max_sum = max(max_sum, max_sum-arr[i-1]+arr[i+k-1]);
	}

	return max_sum;


}

int main(){

//	vector<int> arr = {1, 4, 2, 10, 2, 3, 1, 0, 20};
//
	vector<int> arr = {1, 4, 2, 10, 23, 3, 1, 0, 20};

	cout << "Max Sum " << find_max_sum(arr,4) << "\n";

	return 0;
}
