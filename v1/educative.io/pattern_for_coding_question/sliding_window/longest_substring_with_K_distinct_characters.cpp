/*Longest Substring with K Distinct Characters (medium)

  Find the longest substring with k unique characters in a given string
Given a string you need to print longest possible substring that has exactly M unique characters. If there are more than one substring of longest possible length, then print any one of them.
Examples:

"aabbcc", k = 1
Max substring can be any one from {"aa" , "bb" , "cc"}.

"aabbcc", k = 2
Max substring can be any one from {"aabb" , "bbcc"}.

"aabbcc", k = 3
There are substrings with exactly 3 unique characters
{"aabbcc" , "abbcc" , "aabbc" , "abbc" }
Max is "aabbcc" with length 6.

"aaabbb", k = 3
There are only two unique characters, thus show error message.
Source: Google Interview Question.
*/


#include<iostream>
#include<vector>
#include<set>
using namespace std;

int long_substring(string str, int k){

	set<char> set;
	int start = 0; int end = 0;

	int max_len = INT8_MIN;

	for(int i = 0 ; i<str.length();i ++){
		set.insert(str[i]);

		if(set.size() == k){
			string sub_str = str.substr(start,i-start+1);
			cout << sub_str << "\n";

			int len = sub_str.length();
			max_len = max(len,max_len);
		}
		else if(set.size() > k){
			char trail_char = str[start];
			while(1){
				if(str[start] != trail_char){
					break;
				}
				start++;
			}
			set.erase(trail_char);
		}
	}

	return max_len;


}
int main(){


	string str = "aabbcc";

	cout << long_substring("aabb",3) << "\n";

	return 0;
}
