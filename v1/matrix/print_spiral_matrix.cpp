/* Author : Sukanto Mondal */


/*
Print a given matrix in spiral form
*/

/*
Given a 2D array, print it in spiral form. See the following examples.

Examples:

Input:
        1    2   3   4
        5    6   7   8
        9   10  11  12
        13  14  15  16
Output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10


Input:
        1   2   3   4  5   6
        7   8   9  10  11  12
        13  14  15 16  17  18
Output:
1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11
*/


#include <iostream>
#include <vector>
using namespace std;

void print_spiral(vector<vector<int>> &arr, int m, int n){


	int x = 0, y = 0;

	// x = starting row number
	// y = starting column number
	//
	while (x <= m && y <= n)
	{
		for(int i = y; i <= n ; i++){
			cout << arr[x][i] << " "; 
		}
		x++;

		for(int i = x; i <= m ; i++)
		{
			cout << arr[i][n] << " ";
		}
		n--;

		if(x<= m)
		{
			for(int i = n ; i >= y ; i-- )
			{
				cout << arr[m][i] << " ";
			}
			m--;
		}

		if(y <= n) {
			for(int i = m ; i >= x ; i--){	
				cout << arr[i][y] << " ";
			}
			y++;
		}

	}
}

int main()
{
	vector<vector<int>> arr = { {1,  2,  3,  4,  5,  6}, 
        {7,  8,  9,  10, 11, 12}, 
        {13, 14, 15, 16, 17, 18} 
    	}; 

	print_spiral(arr,arr.size()-1,arr[0].size()-1);
	return 0;

}




