/*Problem statement
Given an infinite sorted array (or an array with unknown size), find out if a given number key is present in the array.
Write a function to return the index of the key if it is present in the array, otherwise return -1.
*/

#include<iostream>
#include<vector>
using namespace std;



class array_reader{
	public:
	vector<int> arr;
	int get(int index){
		if(index > arr.size()-1){
			return INT32_MAX;
		}
		else{

			return arr[index];
		}
	}
};

int binary_search(array_reader arr, int start, int end, int key){

	cout << start << " " << end << "\n";

	while(start <= end){
		int mid = start + (end-start)/2;
		if(arr.get(mid) == key){
			return mid;
		}

		if(arr.get(mid) < key){
			start = mid+1;
		}else{
			end = mid-1;
		}
	}

	return -1;
}

int search(array_reader arr, int key){

	int start = 0; int end = 1;

	while(arr.get(end) < key){
		int new_start = end+1;
		int curr_dis = end-start+1;
		start = new_start;
		end = new_start + (curr_dis*2)-1;
	}

	return binary_search(arr, start, end, key);
}


int main(){
	array_reader arr;
	arr.arr= { 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30 };

	cout << search(arr,1) << "\n";

	return 0;
}
