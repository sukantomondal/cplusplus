/*Length of the longest substring without repeating characters
Given a string str, find the length of the longest substring without repeating characters.

For “ABDEFGABEF”, the longest substring are “BDEFGA” and “DEFGAB”, with length 6.
For “BBBB” the longest substring is “B”, with length 1.
For “GEEKSFORGEEKS”, there are two longest substrings shown in the below diagrams, with length 7
.

The desired time complexity is O(n) where n is the length of the string.

*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> set;

        int max_len = 0;
        int start = 0;

        for(int i = 0; i< s.length(); i++){

            if(set.find(s[i]) == set.end()){
                set[s[i]] = i;
                max_len = max(max_len, i-start+1);
            }else{

                for(int j = start; j < set[s[i]] ; j++){
                    set.erase(s[j]);
                }
                start = set[s[i]]+1;
                set[s[i]] = i;

            }
        }

        return max_len;
}

int main(){

	cout << lengthOfLongestSubstring("GEEKSFORGEEKS");

	return 0;
}


