/*Longest subsequence such that difference between adjacents is one | Set 2
Given an array of size n. The task is to find the longest subsequence such that difference between adjacents is one. Time Complexity of O(n) is required.

Examples:

Input :  arr[] = {10, 9, 4, 5, 4, 8, 6}
Output :  3
As longest subsequences with difference 1 are, "10, 9, 8", 
"4, 5, 4" and "4, 5, 6".

Input :  arr[] = {1, 2, 3, 2, 3, 7, 2, 1}
Output :  7
As longest consecutive sequence is "1, 2, 3, 2, 3, 2, 1".



 (Efficient Approach): The idea is to create a hash map having tuples in the form (ele, len), where len denotes the length of the longest subsequence ending with the element ele. Now, for each element arr[i] we can find the length of the values arr[i]-1 and arr[i]+1 in the hash table and consider the maximum among them. Let this maximum value be max. Now, the length of longest subsequence ending with arr[i] would be max+1. Update this length along with the element arr[i] in the hash table. Finally, the element having the maximum length in the hash table gives the longest length subsequence.

*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int longest_sequence(vector<int> arr){

	int max_len = 0;
	unordered_map<int, int> map;

	for(int i = 0 ; i < arr.size(); i++){

		if(map.find(arr[i]-1) == map.end() && map.find(arr[i]+1) == map.end()){
			map[arr[i]]++;
		}
		else{

			/*if(map[arr[i]+1] > map[arr[i]-1]){
				map[arr[i]] = map[arr[i]+1]+1;
			}else{
				map[arr[i]] = map[arr[i]-1]+1;
			}*/

			map[arr[i]] = 1+ max(map[arr[i]+1], map[arr[i]-1]);
		}

		cout << map[arr[i]] << " ";

		if(max_len < map[arr[i]])
			max_len = map[arr[i]];
	}

	cout << "\n";

	return max_len;


}


int main(){
	vector<int> arr =  {10, 9, 4, 5, 4, 8, 6};
	cout << longest_sequence(arr);
	return 0;
}
