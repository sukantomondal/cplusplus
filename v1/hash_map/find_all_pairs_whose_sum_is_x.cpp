/*Given two unsorted arrays of distinct elements, the task is to find all pairs from both arrays whose sum is equal to X.

Examples:

Input :  arr1[] = {-1, -2, 4, -6, 5, 7}
         arr2[] = {6, 3, 4, 0}  
         x = 8
Output : 4 4
         5 3

Input : arr1[] = {1, 2, 4, 5, 7} 
        arr2[] = {5, 6, 3, 4, 8}  
        x = 9
Output : 1 8
         4 5
         5 4

	 */


#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


void print_pair(vector<int> arr1, vector<int>arr2,int x){

	unordered_set<int> set;

	for(int i = 0;i < arr1.size(); i++){
		set.insert(arr1[i]);
	}

	for(int i = 0 ; i<arr2.size(); i++){

		if(set.find(x-arr2[i]) != set.end()){
			cout << x-arr2[i] << " " << arr2[i] << "\n";

		}
	}

	
}

int main(){

	vector<int> arr1 = {1, 2, 4, 5, 7};
	vector<int> arr2 = {5, 6, 3, 4, 8};

	int x = 9;

	print_pair(arr1,arr2,x);

	return 0;
}
