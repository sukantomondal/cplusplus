/*Author : Sukanto Mondal */

/*Print all triplets in sorted array that form AP
Given a sorted array of distinct positive integers, print all triplets that form AP (or Arithmetic Progression)

Examples :

Input : arr[] = { 2, 6, 9, 12, 17, 22, 31, 32, 35, 42 };
Output :
6 9 12
2 12 22
12 17 22
2 17 32
12 22 32
9 22 35
2 22 42
22 32 42

Input : arr[] = { 3, 5, 6, 7, 8, 10, 12};
Output :
3 5 7
5 6 7
6 7 8
6 8 10
8 10 12

*/

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

void print_triplet_ap(vector<int> nums){

	unordered_set<int> s;
	for(int i = 0 ; i < nums.size(); i++){
		for(int j = i+1; j< nums.size(); j++){

			int diff = nums[j] - nums[i];

			if(s.find(nums[i]-diff) != s.end()){
				cout << nums[i] -diff << " " << nums[i] << " " << nums[j] << "\n";
			}
		}

		s.insert(nums[i]);

	}
}

int main(){

	vector<int> nums = { 2, 6, 9, 12, 17, 22, 31, 32, 35, 42 };

	print_triplet_ap(nums);
	return 0;
}
