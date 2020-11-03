/* Permutation of sets */


#include<iostream>
#include<vector>
using namespace std;


void permutation_sets(vector<vector<int>> mat, int level, vector<int> result){

	if(level == result.size()){

		for(int x : result){
			cout <<x<<" ";
		}
		cout << "\n";

		return;
	}

	for(int i = 0 ; i < mat[level].size(); i++){
		result[level] = mat[level][i];
		permutation_sets(mat,level+1, result);
	}
}


int main(){


	vector<vector<int>> mat(5);

	mat[0] = {1,2,3,4,5};
	mat[1] = {6,7,9,8};
	mat[2] = {0,-1,-2};
	mat[3] = {-3,-4,-5};
	mat[4] = {-9,-8};

	vector<int> result(5);

	permutation_sets(mat,0,result);

	return 0;
}
