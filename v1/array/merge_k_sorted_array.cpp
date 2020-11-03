/*Merge k sorted arrays | Set 2 (Different Sized Arrays)
Given k sorted arrays of possibly different sizes, merge them and print the sorted output.

Examples:

Input: k = 3 
      arr[][] = { {1, 3},
                  {2, 4, 6},
                  {0, 9, 10, 11}} ;
Output: 0 1 2 3 4 6 9 10 11 

Input: k = 2
      arr[][] = { {1, 3, 20},
                  {2, 4, 6}} ;
Output: 1 2 3 4 6 20 


An efficient solution is to use heap data structure. The time complexity of heap based solution is O(N Log k).

1. Create an output array.
2. Create a min heap of size k and insert 1st element in all the arrays into the heap
3. Repeat following steps while priority queue is not empty.
…..a) Remove minimum element from heap (minimum is always at root) and store it in output array.
…..b) Insert next element from the array from which the element is extracted. If the array doesn’t have any more elements, then do nothing.


*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void merge_array(vector<vector<int>> arr){

	vector<int> merge_array;

	priority_queue< pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq; // min heap

	for(int i =0 ; i < arr.size(); i++){

		pq.push({arr[i][0],{i,0}});
	}

	while(!pq.empty()){

		pair<int,pair<int,int>> curr = pq.top(); // minimum element;

		merge_array.push_back(curr.first);

		if(curr.second.second+1 < arr[curr.second.first].size()){
			pq.pop();
			pq.push({arr[curr.second.first][curr.second.second+1],{curr.second.first, curr.second.second+1}});
		}else{

			pq.pop();
		}
	}

	for(int x : merge_array){

		cout << x << " ";
	}

	cout << "\n";
}

int main(){

	vector<vector<int>> arr = { {1, 3},
                  {2, 4, 6},
                  {0, 9, 10, 11}} ;

	merge_array(arr);
	return 0;
}
