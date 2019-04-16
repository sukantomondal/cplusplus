/* Author: Sukanto Mondal*/

//Rotate a matrix by 90 degree

#include <iostream>
#include <algorithm>

#define N 3

using namespace std;

/* transpose a matrix */

void transpose_matrix (int arr[N][N]){

	for(int i = 0 ; i < N; i ++){
		for (int j = i+1; j < N; j++){
		     swap(arr[i][j],arr[j][i]);
		}
	}
}


/* Reverse a Matrix */
void reverse_matrix(int arr[N][N]){

	for (int i = 0; i < N/2; i ++ ){
		for(int j = 0; j < N ; j++){
			swap(arr[i][j],arr[N-i-1][j]);
		}
	}

}

/* Print a matrix */
void print_matrix(int arr[N][N]){

	for (int i = 0; i < N ; i ++){
		for (int j = 0 ; j < N ; j++){
			cout << arr[i][j] << " ";
		}

		cout << "\n";
	}
	cout << "\n";

}

int main (){

	int arr[N][N] = {{1,2,3},{4,5,6},{7,8,9}};

	cout << "Given Matrix\n";
	print_matrix (arr);
	cout << "Transpose Matrix\n";
	transpose_matrix(arr);
	print_matrix(arr);
	cout << "Rotation 90 degree\n";
	reverse_matrix(arr);
	print_matrix (arr);
	cout << "\n";
	return 0;
}
