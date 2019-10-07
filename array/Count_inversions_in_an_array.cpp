/*Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

Example:
The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
*/


#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int> &arr, int left, int mid, int right){

	int i, j , k;

	i = left;
	j = mid+1;

	vector<int> tmp;

	int inversion_count = 0;

	while(i <=mid && j <= right){

		if(arr[i] <= arr[j]){
			tmp.push_back(arr[i++]);
		}else{
			inversion_count += (mid-i)+1;
			tmp.push_back(arr[j++]);
		}
	}


	while(i<= mid){
		tmp.push_back(arr[i++]);
	}
	while(j<= right){
		tmp.push_back(arr[j++]);
	}

	k = 0;
	for(int p = left; p<= right; p++){
		arr[p] = tmp[k++];
	}

	return inversion_count;
	
}

int merge_sort(vector<int> &arr, int left, int right){

	if(left >= right)
		return 0;

	int inversion_count = 0;

	int mid = left + (right-left)/2;

	inversion_count = merge_sort(arr, left, mid);
	inversion_count += merge_sort(arr, mid+1, right);

	inversion_count += merge(arr, left, mid, right);

	return inversion_count;
}

int main(){

	vector<int> arr = { 1, 20, 6, 4, 5 }; //{3,2,4,23,1,0,-1};

	int inversion_count = merge_sort(arr, 0, arr.size()-1);

	for(auto x : arr){
		cout << x << " ";
	}

	cout << "\n";

	cout << "The number of inversion count is : " << inversion_count << "\n";

	return 0;
}
