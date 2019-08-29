/*Find three element from different three arrays such that that a + b + c = sum
Given three integer arrays and a “sum”, the task is to check if there are three elements a, b, c such that a + b + c = sum and a, b and c belong to three different arrays.

Examples :

Input : a1[] = { 1 , 2 , 3 , 4 , 5 };
    a2[] = { 2 , 3 , 6 , 1 , 2 };
    a3[] = { 3 , 2 , 4 , 5 , 6 };  
        sum = 9
Output : Yes
1  + 2  + 6 = 9  here 1 from a1[] and 2 from
a2[] and 6 from a3[]   
    
Input : a1[] = { 1 , 2 , 3 , 4 , 5 };
    a2[] = { 2 , 3 , 6 , 1 , 2 };
    a3[] = { 3 , 2 , 4 , 5 , 6 };   
         sum = 20 
Output : No
*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

void find_elements(vector<int> arr1, vector<int> arr2, vector<int> arr3, int sum){

	set<int> set;

	for(int i = 0 ; i < arr3.size(); i++){
		set.insert(arr3[i]);
	}


	for(int i = 0 ; i < arr1.size(); i++){

		for(int j = 0 ; j< arr2.size(); j++){

			if(set.find(sum - arr1[i]- arr2[j]) != set.end()){

				cout << arr1[i] << "  "<< arr2[j] << "  "<< *set.find(sum-arr1[i] - arr2[j]) << "\n";
			}
		}
	}
}
int main(){

	vector<int> arr1 = { 1 , 2 , 3 , 4 , 5 };
	vector<int> arr2 = { 2 , 3 , 6 , 1 , 2 };
	vector<int> arr3 = { 3 , 2 , 4 , 5 , 6 };

	find_elements(arr1,arr2,arr3,9);

	return 0;
}
