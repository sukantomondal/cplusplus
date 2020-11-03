/*Given a sorted array arr[] and a value X, find the k closest elements to X in arr[]. 
Examples:

Input: K = 4, X = 35
       arr[] = {12, 16, 22, 30, 35, 39, 42, 
               45, 48, 50, 53, 55, 56}
Output: 30 39 42 45
Note that if the element is present in array, then it should not be in output, only the other closest elements are required.

*/

#include<iostream>
#include<vector>
using namespace std;


void find(vector<int> arr, int x, int k){


	int l = 0;
	int r = arr.size()-1;

	int mid =-1;
	while (l<r){

		mid = l+ (r-l)/2;

		//cout << mid << " ";

		if(arr[mid] == x || (arr[mid]< x && arr[mid+1]> x)){
			break;
		}else if(arr[mid] < x ){

			l = mid+1;	
		}else{
			r = mid-1;
		}
	}


	cout << mid;

}

int main(){
	vector<int> arr = {12, 16, 22, 30, 35, 39, 42,45, 48, 50, 53, 55, 56};
	find(arr,4,35);

	return 0;
}
