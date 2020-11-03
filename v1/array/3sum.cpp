/*
 *
 
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> res;

        if(nums.size() < 3)
            return res;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size()-2; i++){

            int l = i+1;
            int r = nums.size()-1;
            int sum;

            while(l<r){
                sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    //cout << nums[i] << " " << nums[l] << " " << nums[r] << "\n";
                    vector<int> arr = {nums[i], nums[l], nums[r]};
                    res.push_back(arr);
                    l++;
                    r--;

                    while(l<r && nums[l] == nums[l-1]) l++;
                    while(l<r && nums[r] == nums[r+1]) r--;



                }else if(sum < 0){
                    l++;
                }else{
                    r--;
                }

            }

            while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        }




        return res;
        /*
        set<int> set;

        int sum;
        for(int i = 0 ; i < nums.size(); i++){

            set.clear();
            int curr_sum = - nums[i];
            for(int j =i+1 ; j < nums.size(); j++){
                if(set.find(curr_sum - nums[j]) != set.end()){
                    cout << nums[i] << " " << nums[j] << " "<< curr_sum - nums[j] << "\n";
                }

                set.insert(nums[j]);
            }
        }
        */

        return res;

    }



int main(){

	return 0;
}
