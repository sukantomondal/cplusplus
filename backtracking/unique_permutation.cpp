#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 void unique_permutation(vector<int> &nums , vector<int>index, vector<int>result, int level, vector<vector<int>> &res){
         
         if(level == nums.size()){
             res.push_back(result);
             return;
         }
         
         for(int i = 0 ; i < nums.size(); i++){
             
             if(i > 0 && nums[i] == nums[i-1] && index[i-1] == 0){   // the main understanding is here. why index[i-1] == 0 take care of.
                 continue;
             }
             
             if(index[i] == 0){ 
                 index[i] = 1;
                 result[level] = nums[i];
                 unique_permutation(nums, index, result,level+1, res);
                 index[i] = 0;
                
             }
         }
}


int main(){


	vector<int>  nums = {3,3,0,3};

	sort(nums.begin(), nums.end());

	vector<vector<int>> res;
        vector<int> result(nums.size());
        vector<int> index(nums.size(),0);
        unique_permutation(nums,index,result,0, res);

	for(auto x : res){

		for(auto y : x)
			cout << y << " ";

		cout << "\n";
	}
}
