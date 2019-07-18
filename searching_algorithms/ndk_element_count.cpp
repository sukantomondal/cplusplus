/*Given an array of size n and a number k, find all elements that appear more than n/k times
Given an array of size n, find all elements in array that appear more than n/k times. For example, if the input arrays is {3, 1, 2, 2, 1, 2, 3, 3} and k is 4, then the output should be [2, 3]. Note that size of array is 8 (or n = 8), so we need to find all elements that appear more than 2 (or 8/4) times. There are two elements that appear more than two times, 2 and 3.

*/

#include <iostream>
#include <vector>
using namespace std;

struct count_elelment{

	int element;
	int count;
};


void findndk(vector<int> arr, int k){

	int n = arr.size();


	vector <count_elelment> tmp (k-1);

	for(int i= 0; i < k-1; i++){
		tmp[i].count =0;		
	}	


	int i,j,l,p;
	for (int i = 0; i< n; i++){

		for(j = 0; j < k-1; j++){

			if(arr[i]==tmp[j].element){

				tmp[j].count += 1;
				break;
			}
		}

		if(j== k-1){   // if not exist in the tmp

			for(l = 0; l < k-1; l++){

				if(tmp[l].count == 0){

					tmp[l].element = arr[i];
					tmp[l].count = 1;
					break;
				}
			}


			if(l==k-1){

				for( p =0 ; p< k-1; p++){
					tmp[p].count -=1;
				}

			}

		}
	}


	for(i = 0; i < k-1 ; i++){

		int count = 0;

		for(j = 0 ; j< n; j++){
			if(arr[j] == tmp[i].element){

				count++;
			}
		}


		if(count >= n/k){

			cout << "Element " << tmp[i].element <<" Count " << count; 
		}
	}

}


int main(){

	vector<int> arr = {4, 5, 6, 7, 8, 4, 4};
	findndk(arr,2);
}
