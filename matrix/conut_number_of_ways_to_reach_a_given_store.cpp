/*Count number of ways to reach a given score in a Matrix
Given a N x N matrix mat[][] consisting of non-negative integers, the task is to find the number of ways to reach a given score M starting from the cell (0, 0) and reaching the cell (N – 1, N – 1) by going only down(from (i, j) to (i + 1, j)) or right(from (i, j) to (i, j + 1)). Whenever a cell (i, j) is reached, total score is updated by currentScore + mat[i][j].

Examples:

Input: mat[][] = {{1, 1, 1},
{1, 1, 1},
{1, 1, 1}}, M = 4
Output: 0
All the paths will result in a score of 5.

Input: mat[][] = {{1, 1, 1},
{1, 1, 1},
{1, 1, 1}}, M = 5
Output: 6
*/

#include<iostream>
#include<vector>
#include<list>
using namespace std;

bool is_valid_index(vector<vector<int>> arr, int row, int col){

	if(row >= 0 && row < arr.size() && col>=0 && col < arr[0].size()){
		return true;
	}
	return false;
}

void count(vector<vector<int>> arr, int sum, int score, int row, int col , int &no_of_ways){

	if(!is_valid_index(arr,row,col)){
		return;
	}

	sum += arr[row][col];

	if(sum == score){
		no_of_ways++;
		return;
	}
	count(arr,sum,score,row,col+1,no_of_ways);
	count(arr,sum,score,row+1,col,no_of_ways);
}

// dynamic programming way
//
//
void count_dp(vector<vector<int>> arr, int score){

	vector<vector<vector<int>>> path(arr.size(),vector<vector<int>>(arr[0].size()));

	int no_of_ways = 0;

	for(int i = 0 ; i < arr.size(); i++){
		for(int j = 0; j < arr[0].size(); j++){
			if(i == 0 && j == 0){
				path[i][j].push_back(arr[i][j]);
			}else if(i == 0){
				path[i][j].push_back(path[i][j-1][0] + arr[i][j]); 

			}else if(j == 0){
				path[i][j].push_back(path[i-1][j][0] + arr[i][j]);
			}

			else{
				for(int l = 0; l < path[i-1][j].size(); l++){

					//path[i][j].push_back(arr[i][j] + path[i-1][j][l]);

					if(arr[i][j]+path[i-1][j][l] <= score){
						//no_of_ways++;
						//
						path[i][j].push_back(arr[i][j] + path[i-1][j][l]);
					}
				}
				for(int l = 0; l < path[i][j-1].size(); l++){

					//path[i][j].push_back(arr[i][j] + path[i][j-1][l]);

					if(arr[i][j]+path[i][j-1][l] <= score){
						//no_of_ways++;
						//
						path[i][j].push_back(arr[i][j] + path[i][j-1][l]);
					}
				}

			}

			cout << path[i][j].size() << " ";

			//cout << path[i][j] << " ";
		}
		cout << "\n";
	}


	cout << path[arr.size()-1][arr[0].size()-1].size() << "\n";

	for(auto x : path[arr.size()-1][arr[0].size()-1]){
		cout << x <<" ";
	}
	cout << "\n";

	cout << no_of_ways << "\n";
}

int main(){

	vector<vector<int>> mat = {{1,1,1},{1,1,1},{1,1,1}};

	int no_of_ways = 0;

	count(mat,0,5,0,0,no_of_ways);

	cout << no_of_ways << "\n";

	count_dp(mat,5);

	return 0;
}
