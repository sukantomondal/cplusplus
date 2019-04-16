/* Author : Sukanto Mondal */

/* Count number of magic tupple */


/*
 *Given an array a[] of n integers, a triplet (a[i], a[j], a[k]) is called Magic Triplet if a[i] < a[j] < a[k] and i < j < k.  The task is to count number of magic triplets in a given array.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.


Output:
In each seperate line print the number of such triplets.


Constraints:
1<=T<=31
1<=N<=10000
1<=A[I]<=5000


Example:
Input:
2
3
3 2 1
4
1 2 3 4

Output:
0
4
*/

#include<iostream>
#include<vector>
using namespace std;


int count_magic_triplet(vector<int> nums){
    
    int count = 0;
    int size = nums.size();
    
    int smaller = 0,greater = 0;
    
    for(int i = 0; i<nums.size(); i++){
        
        smaller = 0 ; greater = 0; 
        
        for(int j = 0 ; j< nums.size(); j++){
            if(i==j) continue;
            
            if((nums[j] < nums[i]) && j < i){
                smaller++;
            }
            
            if((nums[j] > nums[i]) && j > i){
                greater++;
            }
        }
        
        count+=(smaller*greater);
        
    }
    
    
    return count;
}

void print_array(vector<int> arr){

	for(int i=0 ; i < arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
}
int main(){

	vector<int> nums = {1,2,3,4};
       	cout << "The number are \n";
	print_array(nums);
	cout << "The number of magic triplets are : " << count_magic_triplet(nums) << "\n";
	return 0;
}
