/* Author : Sukanto Mondal *
 
/*
Program to find the Hidden Number

Given an array of n integers, The task is to find another integer x such that, if all the elements of the array are subtracted individually from the number x, then the sum of all the differences should add to 0. If any such integer exists, print the value of x, else print -1.

Example

Input: arr[] = {1, 2, 3}
Output: 2
Explanation: 
Substracting all the elements of arrays from 2,
The sum of difference is:
1 + 0 + (-1) = 0.


Solution: The idea is to calculate the total sum of the array and divide it by the size of the array. If the sum of the array is perfectly divisible by its size then the quotient obtained from this division operation will be the required hidden number.

*/

#include <iostream>
#include <vector>
using namespace std;

int main(){

	vector<int>arr = {1,2,3,4,5};

	long sum=0;

	for (int i= 0; i < arr.size(); i++){
		sum+=arr[i];
	}

	long x;
	x = sum/arr.size();

	if(x*arr.size() == sum){
		cout << x << "\n";
	}
	else{
		cout << -1 << "\n";
	}

	return 0;
}
