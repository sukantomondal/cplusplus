/* Author : Sukanto Mondal */

/*
 * Given a number N. Write a program to check whether every bit in the binary representation of the given number is set or not.

Input:
First line of input contains a single integer T which denotes the number of test cases. T test cases follows. First line of each test case contains a single integer N which denotes the number to be checked.

Output:
For each test case, print "YES" without quotes if all bits of N are set otherwise print "NO".

Constraints:
1<=T<=1000
0<=N<=1000

Example:
Input:
3
7
14
4
Output:
YES
NO
NO
*/

#include<iostream>
#include<string>
using namespace std;

string check_set_bit(int num){
    int no_of_bits =  sizeof(num) * 8;
    int count = 0;
    while(num && count < no_of_bits){
        if(!(num & 1)){
            return "NO";
        }
        num>>=1;
        count++;
    }

    return "YES";    
}

int main(){
	int num = 3;
	cout << "The check bit status of " << num << " is " << "\""<< check_set_bit(num) << "\"" << "\n";
	return 0;
}
