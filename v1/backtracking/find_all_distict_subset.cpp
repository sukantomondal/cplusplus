/*Find all distinct subsets of a given set
Given a set of positive integers, find all its subsets. The set can contain duplicate elements, so any repeated subset should be considered only once in the output.

Examples:

Input:  S = {1, 2, 2}
Output:  {}, {1}, {2}, {1, 2}, {2, 2}, {1, 2, 2}

Explanation: 
The total subsets of given set are - 
{}, {1}, {2}, {2}, {1, 2}, {1, 2}, {2, 2}, {1, 2, 2}
Here {2} and {1, 2} are repeated twice so they are considered 
only once in the output
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

void find_all_subset(vector<int> &arr, vector<int> &res, int start_index, vector<vector<int>> &result){

	result.push_back(res);

	/*cout <<"level:" <<start_index << "\n";

	for(auto x : res)
		cout << x << " ";
	cout << "\n";
	*/

	set<int> set;

	for(int i = start_index; i < arr.size(); i++){
		
		if(set.find(arr[i]) == set.end()){  // use set for uniqe sub set;
			set.insert(arr[i]);
			res.push_back(arr[i]);
			find_all_subset(arr, res, i+1,result);
			res.pop_back();
		}
	}
}


int main(){

	vector<int>arr = {1,2,2};
	vector<vector<int>>result;
	vector<int> res;
	find_all_subset(arr,res,0,result);

	for(auto x : result){

		for(auto y : x ){

			cout << y << " ";
		}
		cout << "\n";
	}
	return 0;
}


