/*Print all possible paths from top left to bottom right of a mXn matrix
The problem is to print all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down.
Examples :

Input : 1 2 3
        4 5 6
Output : 1 4 5 6
         1 2 5 6
         1 2 3 6

Input : 1 2 
        3 4
Output : 1 2 4
         1 3 4

*/

#include<iostream>
#include<vector>
using namespace std;

void get_path(vector<vector<int>> arr, int x, int y, vector<int> path){


	if(x >= arr.size() || y >= arr[0].size()){
		return;
	}

	path.push_back(arr[x][y]);

	if(x== arr.size()-1 && y == arr[0].size()-1){

		for(auto x : path){
			cout << x << " ";
		}

		cout << "\n";
	}
	get_path(arr,x,y+1,path);
	get_path(arr,x+1,y, path);
}

int main(){

	vector<vector<int>> arr = {{1,2,3},{4,5,6}};

	vector<int> path;
	get_path(arr, 0, 0, path);

	return 0;
}

