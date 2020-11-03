/*Length of the longest substring without repeating characters
Given a string str, find the length of the longest substring without repeating characters.

For “ABDEFGABEF”, the longest substring are “BDEFGA” and “DEFGAB”, with length 6.
For “BBBB” the longest substring is “B”, with length 1.
For “GEEKSFORGEEKS”, there are two longest substrings shown in the below diagrams, with length 7

The desired time complexity is O(n) where n is the length of the string.
*/

#include<iostream>
#include<vector>
using namespace std;


void length(string s){

	vector<int> visited (26,-1); // 26 char

	int pre_index, curr_len = 1, max_len = INT8_MIN;

	string st; int start = 0;
	
	visited[s[0]-'a'] = 0;

	for(int i = 1; i< s.length(); i++){
		pre_index = visited[s[i]-'a'];

	
	/* If the currentt character is not present in the
        already processed substring or it is not part of
        the current NRCS, then do cur_len++ */

		if(pre_index == -1 || i-curr_len > pre_index){
			cout << s[i] << "\n";
			curr_len ++;

		}
		else{

			if(max_len < curr_len){
				max_len = curr_len;
				st= s.substr(start, max_len);
			}

			start = pre_index +1;
			curr_len = i - pre_index;
		}

		visited[s[i]-'a'] = i;
	}


	if(max_len < curr_len){
		max_len = curr_len;
		st = s.substr(start, max_len);
	}

	cout << max_len << " "<< st << "\n";
}


int main(){

	string s = "geeksforgeeks";
	length(s);
	return 0;
}



