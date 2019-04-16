/* Author : Sukanto Mondal */

/*
 * Find a sorted subsequence of size 3 in linear time
Given an array of n integers, find the 3 elements such that a[i] < a[j] < a[k] and i < j < k in 0(n) time. If there are multiple such triplets, then print any one of them.
Examples:

Input:  arr[] = {12, 11, 10, 5, 6, 2, 30}
Output: 5, 6, 30

Input:  arr[] = {1, 2, 3, 4}
Output: 1, 2, 3 OR 1, 2, 4 OR 2, 3, 4

Input:  arr[] = {4, 3, 2, 1}
Output: No such triplet
*/


#include<iostream>
#include<vector>
using namespace std;
void magic_triplet(vector<int> nums){
    
    int count = 0;
    int size = nums.size();
    
    int min_index = 0, max_index = size-1;
    
    vector<int> smaller(size);
    vector<int> greater(size);
    
    smaller[0] = -1;
    
    for(int i = 1; i < size; i++){
        
        if(nums[i] < nums[min_index]){
            min_index = i;
            smaller[i]= -1;
        }
        else{
            smaller[i]= min_index;
        }
    }
    
    greater[size-1] = -1;
    
    for(int j = size-2; j>=0; j--){
        
        if(nums[j] > nums[max_index]){
            max_index = j;
            greater[j] = -1;
        }else{
            greater[j] = max_index;
        }
    }
    
    for(int i = 0 ; i < size; i++){
        
        if(smaller[i]!=-1 && greater[i]!=-1){
            cout << "A triplet is :" << nums[smaller[i]] <<" "<< nums[i] <<" "<< nums[greater[i]] << "\n";
	    return;
        }
    }

    cout << "No such triplet\n";

}

void print_array(vector<int> arr){

	for(int i = 0 ; i < arr.size(); i++ )
		cout << arr[i] << " ";

}

int main(){

	vector<int> nums = {12, 11, 10, 5, 6, 2, 30};

	cout << "The array is \n";
	print_array(nums);
	cout << "\n";
	magic_triplet(nums);
	return 0;
}
