/*trap rain water */
/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

https://leetcode.com/problems/trapping-rain-water/

*/


#include<iostream>
#include<vector>
using namespace std;


int trap(vector<int>& height) {

        int n = height.size();

        if(n < 3)
            return 0;

        vector<int> left(height.size());
        vector<int> right(height.size());

        int max = height[0];
        left[0] = -1;

        for(int i = 1 ; i < height.size(); i++){
            left[i] = max;
            if(max<height[i]){
                max = height[i];
            }
        }

        max = height[n-1];
        right[n-1] = -1;

        for(int i =  n-2; i >= 0 ; i--){
            right[i] = max;
            if(max< height[i]){
                max = height[i];
            }
        }
        int ans = 0;
        for(int i = 1 ; i < n-1 ; i++){
            int m = min(left[i] - height[i], right[i] - height[i]);
            if(m>0)
                ans+=m;
        }

        return ans;
}


int main(){

	vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};

	cout << trap(arr);

	return 0;
}
