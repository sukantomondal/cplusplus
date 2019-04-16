/* Author : Sukanto Mondal */

/*You are given two numbers A and B. Write a program to count number of bits needed to be flipped to convert A to B.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. The first line of each test case is A and B separated by a space.

Output:
For each testcase, in a new line, print the number of bits needed to be flipped.

Constraints:
1 ≤ T ≤ 100
1 ≤ A, B ≤ 103

Example:
Input:
1
10 20
Output:
4

Explanation:
Testcase1:
A  = 01010
B  = 10100
Number of bits need to flipped = set bit count in A XOR B value i.e. 4

*/

#include<iostream>
using namespace std;

int bit_difference(int a, int b){

	int num = a^b;
	int count_set_bit = 0;

	while(num){

		if(num & 1){
			count_set_bit++;
		}
		num >>=1;
	}

	return count_set_bit;
}


int main(){

	int a = 10, b = 20;
	cout << "The bit difference between " << a << " and " << b << " is " << bit_difference(a,b) << "\n";

	return 0;
}
