/* Author : Sukanto Mondal */


/* Find number of island in a binary matrix */

/*Given a boolean 2D matrix, find the number of islands. A group of connected 1s forms an island. For example, the below matrix contains 5 islands

Example:

Input : mat[][] = {{1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1},
                   {1, 0, 0, 1, 1},
                   {0, 0, 0, 0, 0},
                   {1, 0, 1, 0, 1}
Output : 5
*/


#include<iostream>
#include<vector>
using namespace std;
void island(vector<vector<int>> &arr, int x, int y){

	if(x<0 || x >= arr.size() || y < 0 || y >= arr.size())
		return;
	if(arr[x][y] == 0)
		return;

	arr[x][y] = 0;

	island(arr,x+1,y);
	island(arr,x-1,y);
	island(arr,x,y+1);
	island(arr,x,y-1);
	island(arr,x+1,y+1);
	island(arr,x-1,y-1);
	island(arr,x+1,y-1);
	island(arr,x-1,y+1);
}

void print_earth(vector<vector<int>>arr){

	for(int i = 0; i < arr.size(); i++){
	
		for(int j = 0; j < arr[i].size(); j++){
		
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(){

	vector<vector<int>> arr = {{1, 1, 0, 0, 0},
                     {0, 1, 0, 0, 1},
                     {1, 0, 0, 1, 1},
                     {0, 0, 0, 0, 0},
                     {1, 0, 1, 0, 1}};

	
	print_earth(arr);
	int count = 0;
	for(int i = 0 ; i < arr.size(); i++)
		for(int j = 0; j < arr[0].size(); j++){
			if(arr[i][j] != 0){
				island(arr,i,j);
				count++;
			}
	}

	cout << "The number of island is : " << count << "\n";

	return 0;
}
