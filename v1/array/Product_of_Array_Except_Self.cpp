/*Product of Array Except Self
 *
 *
 * Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

*/



#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
 


	/* with out using extra space 
	 int n = nums.size();

        if(n == 2){ // base case
            swap(nums[0],nums[1]);
            return nums;
        }

        vector<int> post(n);
        post[n-2] = nums[n-1];

        for(int i = n-3 ; i >= 0 ; i--){
            post[i] = post[i+1]*nums[i+1];
        }

        int pre = nums[0];

        for(int i = 1 ; i < n-1; i++){
            post[i] = pre * post[i];
            pre = pre*nums[i];
        }
        post[n-1] = pre;

        return post;

	*/
	
        int n = nums.size();
        vector<int> res = nums; 
        if(n == 2){ // base case
            swap(res[0],res[1]);
            return res;
        }
        
        vector<int> pre(n);
        vector<int> post(n);
        pre[1] = nums[0];
        post[n-2] = nums[n-1];
        
        for(int i = 2; i < nums.size(); i++){
            pre[i] = pre[i-1] * nums[i-1];
        }
        
        for(int i = n-3 ; i >= 0 ; i--){
            post[i] = post[i+1]*nums[i+1];
        }
        
        for(int i = 1  ; i < n-1; i++){
            res[i] = pre[i] * post[i];
        }
        
        res[0] = post[0];
        res[n-1] = pre[n-1];
        
        return res;
        
    }


int main(){

	vector<int> arr = {1,2,3,4};

	vector<int> res = productExceptSelf(arr);

	for (auto x : res){
		cout << x << " ";
	}

	cout << "\n";

	return 0;
}
