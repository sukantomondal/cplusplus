/*Find position of an element in a sorted array of infinite numbers
*/

/*Suppose you have a sorted array of infinite numbers, how would you search an element in the array?*/

#include<iostream>
#include<vector>
using namespace std;

pair<int, int> find_bound(vector<int> arr, int x) {

	// supose we have at least two elements
	int l = 0, r = 1;

	while (true) {
		if( x>= arr[l] && x <= arr[r]) {
			return {l,r};
		}else if (r*2 < arr.size()){
			l=r;
			r = r*2;
		} else if (r*2 >= arr.size()) {
			l=r;
			r = arr.size() -1;
		}	
		else {
			return {-1,-1};
		}
	}
}

int find_num(vector<int> arr, int l, int r, int x) {

	if(l > r || l < 0)
		return -1;

	int mid = l + (r-l)/2;
	if(x == arr[mid])
		return mid;
	else if (x > arr[mid]) {
		return find_num(arr, mid+1, r,x);
	} else if (x < arr[mid]) {
		return find_num(arr, l, mid-1,x);
	}
}


int main() {
	vector <int> arr = {1,3,4,5,8,9,12,23,45,67,68,70};

	int x = 68;
	pair<int, int> bound = find_bound(arr, x);

	cout << bound.first << " " << bound.second << "\n";

	cout << "Find number " << x << "in :" << find_num(arr, bound.first, bound.second, x) << "\n";

	return 0;
}
