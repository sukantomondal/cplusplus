/*Word Break Problem using Backtracking
Given a valid sentence without any spaces between the words and a dictionary of valid English words, find all possible ways to break the sentence in individual dictionary words.

Example

Consider the following dictionary 
{ i, like, sam, sung, samsung, mobile, ice, 
  cream, icecream, man, go, mango}

Input: "ilikesamsungmobile"
Output: i like sam sung mobile
        i like samsung mobile

Input: "ilikeicecreamandmango"
Output: i like ice cream and man go
        i like ice cream and mango
        i like icecream and man go
        i like icecream and mango
*/


#include<iostream>
#include<vector>
#include<set>
using namespace std;



bool is_in_distionary(set<string> &word_set , string st){

	if(word_set.find(st) == word_set.end()){
		return false;
	}
	return true;
}

void word_break(set<string> word_set ,string st, vector<string> result){
	int len = st.length();

	for(int i = 1 ; i <= len ; i++){

		string pre_st = st.substr(0,i);
		string suf_st = st.substr(i,len-i);

		if(is_in_distionary(word_set, pre_st)){
			result.push_back(pre_st);

			if(i== len){
				
				for(auto x : result){
					cout << x << " ";
				}
				cout << "\n";
			        return;	
			}

			word_break(word_set, suf_st, result);
			result.pop_back(); // backtrack
		}
	}
}

int main(){

	vector<string> words = {"i", "like", "sam", "sung", "samsung", "mobile", "ice", "cream", "icecream", "and","man", "go", "mango"};

	set <string> word_set;

	for(auto x : words){
		word_set.insert(x);
	}

	vector<string> result;
	string st = "ilikeicecreamandmango";
	word_break(word_set, st, result);
	return 0;
}
