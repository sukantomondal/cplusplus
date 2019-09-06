/*Reversal algorithm for array rotation
Write a function rotate(arr[], d, n) that rotates arr[] of size n by d elements.
Example :

Input :  arr[] = [1, 2, 3, 4, 5, 6, 7]
         d = 2
Output : arr[] = [3, 4, 5, 6, 7, 1, 2] 

*/



#include<iostream>
#include<vector>
using namespace std;
void reverse(vector<int> &arr, int l, int r){
	while(l < r){
		swap(arr[l], arr[r]);
		l++; r--;
	}
}



void rotate(vector<int> &arr, int d){

	reverse(arr, 0, d-1);
	reverse(arr,d, arr.size()-1);
	reverse(arr, 0, arr.size()-1);
}

void print(vector<int> arr){

	for(auto x : arr){
		cout << x << " ";
	}

	cout << "\n";
}
int main(){
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
	rotate(arr, 2);

	print(arr);

	return 0;
}
