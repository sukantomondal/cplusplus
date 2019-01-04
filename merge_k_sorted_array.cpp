/* Author : Sukanto Modnal */


/*Given k sorted arrays of possibly different sizes, merge them and print the sorted output.

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
*/


#include <iostream>
#include <queue>
#include <vector>
#include <functional> // for greater

using namespace std;

// first element is the store value
// second element is the pair with first element array index 
// and seccond element the index of element in the selected array
 
typedef pair<int,pair<int,int>> pqc; // priority queue content

vector<int> merge_array(vector<vector<int>> arr){
	
	vector<int> output;
	priority_queue<pqc,vector<pqc>,greater<pqc>> pq;

	// insert first elemet of the each array;
	
	for (int i=0 ; i < arr.size(); i++){
		pq.push({arr[i][0],{i,0}});
	}

	while(!pq.empty()){
		pqc t = pq.top();
		pq.pop();

		output.push_back(t.first); // push back current minimum element

		int i = t.second.first; // array number
		int j = t.second.second; // index of element in array

		if(j+1 < arr[i].size())
			pq.push({arr[i][j+1],{i,j+1}});	
	}

	return output;

}


void print_array(vector<int> arr){

	for (int i = 0; i< arr.size(); i++)
		cout << arr[i] << " ";
	cout << "\n";

}

int main(){

	vector<vector<int>> arr = {{1,3},{2,4,6},{0,9,10,11}};
	cout << "The merge output array is :\n";
	vector<int> output = merge_array(arr);
	print_array(output);
	return 0;
}
