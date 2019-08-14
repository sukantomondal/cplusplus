/*
 * Check if an array can be divided into pairs whose sum is divisible by k
Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.
Examples:

Input: arr[] = {9, 7, 5, 3},
k = 6
Output: True
We can divide array into (9, 3) and
(7, 5). Sum of both of these pairs
is a multiple of 6.

Input: arr[] = {92, 75, 65, 48, 45, 35},
k = 10
Output: True
We can divide array into (92, 48), (75, 65)
and (45, 35). Sum of all these pairs is a
multiple of 10.

Input: arr[] = {91, 74, 66, 48}, k = 10
Output: False

Recommended: Please solve it on “PRACTICE ” first, before moving on to the solution.
A Simple Solution is to iterate through every element arr[i]. Find if there is another not yet visited element that has remainder as (k – arr[i]%k). If there is no such element, return false. If a pair is found, then mark both elements as visited.

Time complexity of this solution is O(n2 and it requires O(n) extra space.

An Efficient Solution is to use Hashing.

1) If length of given array is odd, return false.
    An odd length array cannot be divided into pairs.
2) Traverse input array and count occurrences of
    all reminders.
      freq[arr[i] % k]++
3) Traverse input array again.
   a) Find the remainder of the current element.
   b) If remainder divides k into two halves, then
      there must be even occurrences of it as it
      forms pair with itself only.
   c) If the remainder is 0, then there must be
      even occurrences.
   c) Else, number of occurrences of current
      the remainder must be equal to a number of
      occurrences of "k - current remainder".

     */


#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


bool can_pair(vector<int> arr, int k){

	if(arr.size()%2 != 0){ // if there is odd number of element the pair can not be formed
		return false;
	}

	unordered_map<int, int> fre;

	for(int i = 0 ; i< arr.size(); i++){
		fre[arr[i]%k]++;
	}

	for(auto x : fre){
		cout << x.first << "  " << x.second << "\n";
	}

	for(int i = 0 ; i < arr.size(); i++){

		int rem = arr[i]%k;

		if(rem == 0 || 2*rem == k){
			if(fre[rem]%2 != 0)
				return false;
		}else if(fre[rem] != fre[k-rem]){
			return false;
		}
	}

	return true;
}


int main(){
	vector<int> arr = {93, 75, 65, 48, 45, 35};

	int k = 10;
	cout << can_pair(arr,k) << "\n"; 

	return 0;
}
