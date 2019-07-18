#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int> arr, int l, int r, int x){

	if(l>r)
		return -1;

	if(l==r && arr[l] == x)
		return l;

	int mid = (l+r)/2;

	if(arr[mid] == x)
		return mid;

	if(arr[mid] < x){
	 	return binary_search(arr, mid+1,r,x);
	}
	else{
		return binary_search(arr,l,mid-1,x);
	}
}

int count_frequency(vector<int> arr, int x){

	int index = binary_search(arr,0, arr.size()-1,x);

	int n = arr.size();

	int count = 0;

	if(index == -1)
		return 0;

	else{
		int i = index;
		while (arr[i+1] == x && i <= n-1){
			i++;
			count ++;
		}

		i = index;

		while (arr[i-1] == x && i >=0){
			i--;
			count ++;

		}
	}

	return count+1;
}

int main(){

	vector<int> arr = {1,1,2,2,2,2,2,2,2,3,4,4,4,4,4};
	cout << count_frequency(arr,2);
	return 0;
}
