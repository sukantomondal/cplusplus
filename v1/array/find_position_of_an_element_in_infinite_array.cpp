/*Find position of an element in a sorted array of infinite numbers
Suppose you have a sorted array of infinite numbers, how would you search an element in the array?

Source: Amazon Interview Experience.
*/

#include<iostream>
#include<vector>
using namespace std;


pair<int,int> find_bound(vector<int> arr, int key){

	int l = 0, h = 1;

	if(arr[l] == key || arr[h] == key)
		return {l,h};
	while(key > arr[h]){
		l=h;
		h=h*2;
	}

	return {l,h};	
}


int binary_search(vector<int> arr, int l, int h, int key){

	if(l>h)
		return -1;
	int mid = (l+h)/2;

	if(arr[mid] == key)
		return mid;
	if(arr[mid] > key){
		return binary_search(arr,l,mid-1,key);
	}else{
		return binary_search(arr,mid+1,h,key);
	}
}

int main(){
	vector<int> arr = {0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75};

	int key = 15;
	
	pair <int, int> bound = find_bound(arr, key);

	cout << bound.first << " " << bound.second << "\n";
	cout << binary_search(arr, bound.first, bound.second, key);

	return 0;
}
