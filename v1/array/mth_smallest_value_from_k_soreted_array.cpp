/*Find m-th smallest value in k sorted arrays
Given k sorted arrays of possibly different sizes, find m-th smallest value in the merged array.

Examples:

Input: m = 5     
      arr[][] = { {1, 3},
                  {2, 4, 6},
                  {0, 9, 10, 11}} ;
Output: 4
Explanation The merged array would
be {0 1 2 3 4 6 9 10 11}.  The 5-th 
smallest element in this merged
array is 4.

Input: 6 = 2
      arr[][] = { {1, 3, 20},
                  {2, 4, 6}} ;
Output: 20 

*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;



void print_k_smallest_element(vector<vector<int>> arr, int index){

	priority_queue<int> pq;

	for(vector<int> x : arr){
		for(int y: x){
			if(pq.size()== index){
				int curr = pq.top();
				if(y<curr){
					pq.pop();
					pq.push(y);
				}
			}
			else{
				pq.push(y);
			}
		}
	}

	cout << index << "th element is " << pq.top() << "\n";
}


int main(){

	vector<vector<int>> arr = { {1, 3},
                  		{2, 4, 6},
                  		{0, 9, 10, 11}} ;

	print_k_smallest_element(arr,5);
	return 0;
}
