/*Longest Consecutive Subsequence
Given an array of integers, find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
Examples:

Input: arr[] = {1, 9, 3, 10, 4, 20, 2}
Output: 4
The subsequence 1, 3, 4, 2 is the longest subsequence
of consecutive elements

Input: arr[] = {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42}
Output: 5
The subsequence 36, 35, 33, 34, 32 is the longest subsequence
of consecutive elements.

*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

int logest_sequence(vector<int> arr){

	int max_len = 1;

	set<int> s;

	for(int i = 0 ; i < arr.size(); i++){
		s.insert(arr[i]);
	}

	for(int i = 0 ; i< arr.size(); i++){
		int len = 0;
		if(s.find(arr[i]+1) != s.end()){
			int j = arr[i];
			while(s.find(j) != s.end()){
				j++;
				len++;
			}
		}

		max_len = max(max_len, len);
	}

	return max_len;

}


int main(){
	vector<int> arr = {1, 9, 3, 10, 4, 20, 2};
        cout << logest_sequence(arr);	
	return 0;
}
