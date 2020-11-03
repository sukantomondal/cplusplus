




#include<iostream>
#include<vector>
using namespace std;


 int maxProduct(vector<int>& nums) {

        int curr_max= nums[0], pre_max = nums[0], curr_min = nums[0], pre_min = nums[0];

        int ans = nums[0];

        for(int i = 1 ; i < nums.size(); i++){

            curr_max = max(pre_max*nums[i], pre_min*nums[i]);
            curr_max = max(curr_max,nums[i]);
            ans = max(curr_max,ans);
            curr_min = min(pre_max*nums[i], pre_min*nums[i]);
            curr_min = min(curr_min, nums[i]);

            pre_max = curr_max;
            pre_min = curr_min;

        }

        return ans;
    }



int main(){

	vector<int> arr = {-1,-2,0,1,23,2};
	cout << maxProduct(arr);

	return 0;
}
