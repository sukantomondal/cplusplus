/*Sort array after converting elements to their squares
Given a array of both positive and negative integers ‘arr[]’ which are sorted. Task is to sort square of the numbers of the Array.
Examples:

Input  : arr[] =  {-6, -3, -1, 2, 4, 5}
Output : 1, 4, 9, 16, 25, 36 

Input  : arr[] = {-5, -4, -2, 0, 1}
Output : 0, 1, 4, 16, 25

*/


#include<iostream>
#include<vector>
using namespace std;


vector<int> square(vector<int> A){

	int neg_index = -1;

	for(int i = 0 ; i < A.size(); i++){
		if(A[i]<0){
			neg_index = i;
		}
		A[i]= A[i]*A[i];
	}

	

	vector<int> res;
	if(neg_index < 0){
		res = A;
	}
	else{

		int i , j, k;
		i = neg_index, j = neg_index +1; 

		for(k = 0 ; k < A.size(); k++){

			if(i>=0 && j <= A.size()-1){

				if(A[i]< A[j]){
					res.push_back(A[i]);
					i--;
				}else{
					res.push_back(A[j]);
					j++;
				}
			}
			else if (i < 0){
				res.push_back(A[j]);
				j++; 
			}else{
				res.push_back(A[i]);
				i--;
			}
		}
	}

	return res;
}



vector<int> square1(vector<int> A){
	vector<int> res(A.size());
	for(int i = 0 ; i < A.size(); i++){
		A[i] = A[i]*A[i];
	}

	int l = 0, h = A.size()-1, p = A.size()-1;

	while(l<=h){
		if(A[l]<A[h]){
			res[p] = A[h];
			h--;	
		}else{
			res[p]=A[l];
			l++;
		}
		p--;
	}
	return res;
}


int main(){
	vector<int> A = {-7,-3,2,3,11};

	vector<int> res;
	res = square1(A);


	for (auto x : res){

		cout << x << " ";
	}

	cout << "\n";

	return 0;
}
