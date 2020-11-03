/*
 *
 * Find k closest numbers in an unsorted array
Given an unsorted array and two numbers x and k, find k closest values to x.

Examples:

Input : arr[] = {10, 2, 14, 4, 7, 6}, x = 5, k = 3
Output : 4 6 7
Three closest values of x are 4, 6 and 7.

Input : arr[] = {-10, -50, 20, 17, 80}, x = 20, k = 2
  8 Input : arr[] = {10, Output : 17, 20

*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void print_closest_number(vector<int> arr, int number, int close_index){


	priority_queue<pair<int,int>> pq; // max heap;

	for(int x : arr){

		if(pq.size() == close_index){
			pair<int,int> curr = pq.top();
			if(abs(number - x) < abs(number-curr.second)){
				pq.pop();
				pq.push({abs(number-x),x});
			}
		}else
			pq.push({abs(number-x),x});
	}


	while(!pq.empty()){
		cout << pq.top().second << " ";
		pq.pop();
	}

	cout << "\n";
}


int main(){
	vector<int> arr = {10, 2, 14, 4, 7, 6};

	print_closest_number(arr,5,3);
	return 0;
}
