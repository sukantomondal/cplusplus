/*Author : Sukanto Mondal */


/*
 * Sum of bit differences
 * Write a program to find the sum of bit differences in all pairs that can be formed from array elements n. Bit difference of a pair (x, y) is a count of different bits at same positions in binary representations of x and y. For example, bit difference for 2 and 7 is 2. Binary representation of 2 is 010 and 7 is 111 ( first and last bits differ in two numbers).

Input: The first line of input contains an integer T denoting the number of test cases. First line of the test case will contain an array of elements n.
Output: The sum of bit differences of all pairs that can be formed by given array.
Constraints:

1 <=T<= 100

1 <=N<= 10

1 <=a[i]<= 10
Example:

Input:

2
2
1 2
3
1 3 5

Output:

4
8
*/

#include<iostream>
#include<vector>
using namespace std;

int bit_sum(int res){

    int sum_of_bits = 0;
    while(res){
        if(res & 1){
            sum_of_bits++;
        }
        res>>=1;
    }
    return sum_of_bits;
}

int sum_of_bit_difference_all_pair(vector<int> nums){

    int n = nums.size(),res;
    int sum_of_bits = 0;

    for (int i = 0 ; i < n ; i++){
        for(int j = 0 ; j< n ; j++){
            if(i!=j){
                res=nums[i]^nums[j];
                sum_of_bits+=bit_sum(res);
            }
        }

    }

    return sum_of_bits;
}


void print_array(vector<int> arr){

	for(int i = 0; i < arr.size(); i++){
		cout << arr[i]<< " ";
	}
}

int main(){

	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);

	cout << "The number are: \n";
	print_array(nums);	
	cout << "\nThe sum of all pair bit difference is " << sum_of_bit_difference_all_pair(nums) << "\n";
	return 0;
}
