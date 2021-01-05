/*Given a sorted array and a number x, find the pair in array whose sum is closest to x
Difficulty Level : Easy
 Last Updated : 21 Oct, 2020
Given a sorted array and a number x, find a pair in array whose sum is closest to x.
Examples:

Input: arr[] = {10, 22, 28, 29, 30, 40}, x = 54
Output: 22 and 30

Input: arr[] = {1, 3, 4, 7, 10}, x = 15
Output: 4 and 10
*/

#include <iostream>
#include<vector>
#include<utility>
using namespace std;

pair<int,int> closest_pair(vector<int> arr, int x) {
	int l = 0, r = arr.size()-1;

	int diff = abs(x - arr[l] - arr[r]);

	pair<int, int> res;
	while(l<r) {
		if(diff > abs(x - arr[l] - arr[r])) {
			res = {arr[l], arr[r]};
			diff = abs(x - arr[l] - arr[r]);
		}
		if(arr[l] + arr[r] - x < 0)
			l++;
		else 
			r--;	
	}
	return res;
}
int main() {

	vector<int> arr = {10,22,28,29,30,40};

	pair <int, int> p = closest_pair(arr, 54);
	cout << p.first << " " << p.second << "\n";

	return 0;
}
