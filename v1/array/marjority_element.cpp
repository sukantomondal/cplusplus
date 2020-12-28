/* Moors voting algorithm */


#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {

        int first = nums[0], second = nums[0];
        int count1 = 0, count2 = 0;
        for(int i = 0 ; i < nums.size(); i++){

            if(first == nums[i]){
                count1++;
            }else if(second == nums[i]){
                count2++;
            }else if(count1 == 0){
                first = nums[i];
                count1++;
            }else if(count2 == 0){
                second = nums[i];
                count2++;
            }else{
                count1--;
                count2--;
            }
        }


        count1 = 0;
        count2 = 0;
        for(auto x : nums){
            if(x == first)
                count1++;
            if(x == second)
                count2++;
        }

        if(count1 > nums.size()/3)
            return first;
        if(count2 > nums.size()/3)
            return second;

        return -1;
}


int main(){

	vector<int> arr = {1,2,3,1,1};

	cout << "Majority element :" << majorityElement(arr); 

	return 0;
}


