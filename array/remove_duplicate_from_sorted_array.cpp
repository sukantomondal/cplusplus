/*Author : Sukanto Mondal */

#include<iostream>
#include<vector>

using namespace std;

/*
 *
Remove duplicates from sorted array

Given a sorted array, the task is to remove the duplicate elements from the array.

Examples:

Input  : arr[] = {2, 2, 2, 2, 2}
Output : arr[] = {2}
         new size = 1

Input  : arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5}
Output : arr[] = {1, 2, 3, 4, 5}
         new size = 5
*/

void print_array(vector<int> arr){
	for (int i=0; i < arr.size(); i++){
		cout << arr[i]<< " ";
	}
	cout<< "\n";
}

/* When a vector is passed to a function, 
 * a copy of the vector is created. 
 * When we pass an array to a function, a pointer is actually passed.
 * */
 
void remove_duplicate(vector<int> &arr){

	vector<int> temp;
	for(int i = 0; i < arr.size()-1; i++){
		if(arr[i] != arr[i+1]){
			temp.push_back(arr[i]);
		}
	}

	// store the last element as whether it is unique or repeated, it not stored
	temp.push_back(arr[arr.size()-1]);
	arr.swap(temp);
}

void remove_duplicate_without_extra_space(vector<int> &arr){
	int j =0;
	for(int i = 0; i < arr.size()-1; i++){
	
		if(arr[i] != arr[i+1]){
			arr[j++] = arr[i]; 
		}
	}

	arr[j++] =arr[arr.size()-1];
	arr.resize(j);
	print_array(arr);
}
int main(){

	vector<int>arr = {2,2,2,2,2};
	cout<< "The given array is : \n";
	print_array(arr);

	remove_duplicate(arr);

	cout << "The array after removing duplicate \n";
	print_array(arr);


	vector<int> arr2 = {1, 2, 2, 3, 4, 4, 4, 5, 5};

	cout<< "The given array is : \n";
        print_array(arr2);
 
        remove_duplicate_without_extra_space(arr2);
 
        cout << "The array after removing duplicate \n";
        print_array(arr2);

	return 0;
}
