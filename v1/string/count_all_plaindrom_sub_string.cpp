/*https://www.geeksforgeeks.org/count-palindrome-sub-strings-string/
 *
 * Count All Palindrome Sub-Strings in a String | Set 1
Given a string, the task is to count all palindrome sub string in a given string. Length of palindrome sub string is greater than or equal to 2.
Examples:

Input : str = "abaab"
Output: 3
Explanation :
All palindrome substring are :
 "aba" , "aa" , "baab"

Input : str = "abbaeae"
Output: 4
Explanation :
All palindrome substring are :
"bb" , "abba" ,"aea","eae"
We have discussed a similar problem below

*/


#include<iostream>
#include<vector>
using namespace std;

bool is_plaindrome(string s, int low, int high){
	while(low<high){
		if(s[low] != s[high]){
			return false;
		}

		low++;
		high--;
	}
	return true;
}



int count_ps(string s, int low , int high){

	if(low >= high)
		return 0;

	if(low == high){
		return 1;
	}

	if(is_plaindrome(s,low, high)){
		return 1 + count_ps(s,low+1,high) + count_ps(s,low,high-1) - count_ps(s,low+1,high-1);
	}
	else{
		return count_ps(s,low+1,high) + count_ps(s,low,high-1) - count_ps(s,low+1,high-1);
	}
}


int main(){

	string s = "abbaeae";

	cout << count_ps(s,0,s.length()-1);

	return 0;
}
