/*Find four elements a, b, c and d in an array such that a+b = c+d */
/*Given an array of distinct integers, find if there are two pairs (a, b) and (c, d) such that a+b = c+d, and a, b, c and d are distinct elements. If there are multiple answers, then print any of them.

Example:

Input:   {3, 4, 7, 1, 2, 9, 8}
Output:  (3, 8) and (4, 7)
Explanation: 3+8 = 4+7

Input:   {3, 4, 7, 1, 12, 9};
Output:  (4, 12) and (7, 9)
Explanation: 4+12 = 7+9

Input:  {65, 30, 7, 90, 1, 9, 8};
Output:  No pairs found
Expected Time Complexity: O(n2)
*/

#include<iostream>
#include<vector>
#include<map>
#include<utility>
using namespace std;

void check_pair(vector<int> arr){

	map<int,pair<int, int>> sum_pairs;

	for(int i = 0 ; i< arr.size(); i++){
		for(int j = i+1; j < arr.size(); j++){
			int sum = arr[i]+arr[j];
			if(sum_pairs.find(sum) == sum_pairs.end()){
				sum_pairs[sum] = {arr[i],arr[j]};
			}
			else{

				cout << "Pair found " << sum << " a+b " << arr[i] << " " << arr[j] << " c+d " << sum_pairs[sum].first << " "<< sum_pairs[sum].second << "\n";
			}
		}	
	}
}

int main(){

	vector<int> arr = {3, 4, 7, 1, 2, 9, 8};
	check_pair(arr);

	return 0;
}
