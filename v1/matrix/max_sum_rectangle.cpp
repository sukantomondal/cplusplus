/*Author : Sukanto Mondal */

/* Maximum sum rectangle in a 2D matrix */

/* Maximum sum rectangle in a 2D matrix | DP-27
Given a 2D array, find the maximum sum subarray in it. For example, in the following 2D array, the maximum sum subarray is highlighted with blue rectangle and sum of this subarray is 29.
*/

#include<iostream>
#include<vector>
using namespace std;

void kadane(vector<int> arr, int &start, int &end, int &max_sum){

	max_sum = INT32_MIN;
	int curr_max = arr[0];
	int s=0; start = 0; end = 0;

	for(int i = 1; i < arr.size(); i++){
		if(arr[i]> curr_max +arr[i])
			s=i;
		curr_max = max(arr[i], curr_max+arr[i]);

		if(max_sum < curr_max){
			max_sum = curr_max;
			start=s;
			end=i;
		}
	}
}

void max_sum_rect(vector<vector<int>>mat){

	int row = mat.size();
	int col = mat[0].size();
	int global_max = 0;
	int start, end, max_sum;
	int top_row=0, bottom_row=0, top_left =0, bottom_right = 0;

	for(int left = 0; left < col; left++ ){ // left column
		vector<int> temp(row);
		for(int right= left; right< col ; right++){ // right column

			for(int k = 0; k< row; k++){
				temp[k]+=mat[k][right];
			}

			kadane(temp,start,end,max_sum);

			if(global_max < max_sum){
				global_max = max_sum;
				top_row = start;
				bottom_row = end;
				top_left = left;
				bottom_right = right;
			}
		}
	}

	cout << "The rect is " <<"(" << top_row << "," << top_left <<")" << " --- " << "(" << bottom_row << "," << bottom_right <<")"<<"\n"; 
	cout << "The max sum is " << global_max << "\n";
}

int main(){

/*	vector<vector<int>> mat = {{1, 2, -1, -4, -20},  
                       {-8, -3, 4, 2, 1},  
                       {3, 8, 10, 1, 3},  
                       {-4, -1, 1, 7, -6}};

*/	vector<vector<int>> mat = {{1, 2, -1, 4, 20},
                         {-8, -3, 4, 2, 1},
                         {3, 8, 10, -8, 3},
                         {-4, -1, 1, 7, -6}};




	max_sum_rect(mat);
	return 0;
}
