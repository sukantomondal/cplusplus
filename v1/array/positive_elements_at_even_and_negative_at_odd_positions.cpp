/*Positive elements at even and negative at odd positions (Relative order not maintained)
You have been given an array and you have to make a program to convert that array such that positive elements occur at even numbered places in the array and negative elements occur at odd numbered places in the array. We have to do it in place.

There can be unequal number of positive and negative values and the extra values have to left as it is.

Examples:

Input : arr[] = {1, -3, 5, 6, -3, 6, 7, -4, 9, 10}
Output : arr[] = {1, -3, 5, -3, 6, 6, 7, -4, 9, 10}

Input : arr[] = {-1, 3, -5, 6, 3, 6, -7, -4, -9, 10}
Output : arr[] = {3, -1, 6, -5, 3, -7, 6, -4, 10, -9}

*/

#include<iostream>
#include<vector>
using namespace std;

void rearrange(vector<int> &arr){

	int p_index= 0; int n_index = 1;
	while (p_index < arr.size() && n_index < arr.size()){

		if(arr[p_index] < 0 && arr[n_index] > 0){
			swap(arr[p_index], arr[n_index]);
		}else if(arr[p_index]>0){
			p_index+=2;
		}else if(arr[n_index]<0){
			n_index+=2;
		}
	}

}

void print(vector<int> arr){

	for(auto x : arr){
		cout << x << " ";
	}
	cout << "\n";
}

int main(){


	vector<int> arr = {-1, 3, -5, 6, 3, 6, -7, -4, -9, 10};
	print(arr);
	rearrange(arr);
	print(arr);

	return 0;
}
