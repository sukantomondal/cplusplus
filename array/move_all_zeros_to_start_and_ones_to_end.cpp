/*Move all zeros to start and ones to end in an Array of random integers
Given an array arr[] of random integers, the task is to push all the zero’s in the array to the start and all the one’s to the end of the array. Note that the order of all the other elements should be the same.

Example:

Input: arr[] = {1, 2, 0, 4, 3, 0, 5, 0}
Output: 0 0 0 2 4 3 5 1

Input: arr[] = {1, 2, 0, 0, 0, 3, 6};
Output: 0 0 0 2 3 6 1

*/

#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int> &arr, int l, int r){

	while(l<r){
		swap(arr[l],arr[r]);
		l++; r--;
	}
}

void print(vector<int> &arr){

	for(auto x : arr){
		cout << x << " ";
	}

	cout << "\n";
}
void move (vector<int> &arr){

	int count_not_1=0;

	for(int i = 0; i < arr.size(); i++){
		if(arr[i] != 1){
			arr[count_not_1++]= arr[i];
		}
	}

	for(int i = count_not_1; i< arr.size(); i++){
		arr[i] = 1;
	}

	int count_no_binary=0;

	for(int i = 0 ; i < count_not_1; i++){
		if(arr[i] != 0){
			arr[count_no_binary++] = arr[i];
		}
	}

	for(int i = count_no_binary; i < count_not_1; i++){
		arr[i] = 0;
	}

	reverse(arr,0,count_no_binary-1);
	reverse(arr, 0, count_not_1-1);
	print(arr);
}



// if the order does not matter then it is dutch national flag problem
//

void move1(vector<int> &arr){

	int l = 0;
	int r = arr.size()-1;
	int m = 0;

	while(m<r){
		if(arr[m] == 0){
			swap(arr[m],arr[l]);
			l++; m++;
		}else if(arr[m] == 1){
			swap(arr[m], arr[r]);
			r--;
		}else{
			m++;
		}
	}
}



int main(){

	vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0}; //{1, 2, 0, 0, 0, 3, 6};

	move1(arr);

	print(arr);
	return 0;
}
