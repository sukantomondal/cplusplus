/* Letter Combinations of a Phone Number*/

/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


Example:

map['2'] = {'a','b','c'};
        map['3'] = {'d','e','f'};
        map['4'] = {'g','h','i'};
        map['5'] = {'j','k','l'};
        map['6'] = {'m','n','o'};
        map['7'] = {'p','q','r','s'};
        map['8'] = {'t','u','v'};
        map['9'] = {'w','x','y','z'};

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.

*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void generate(unordered_map<char, vector<char>> &map, string in_str, int index, string res_str, vector<string> &res){
        if(in_str.length() == 0)
            return;
        if(in_str.length() == index){
            res.push_back(res_str);
            return;
        }
        for(int i = 0 ; i < map[in_str[index]].size(); i++){    
            generate(map, in_str, index+1, res_str + map[in_str[index]].at(i), res);
        }
    }

vector<string> letterCombinations(string digits) {
        
        unordered_map<char, vector<char>> map;
        map['2'] = {'a','b','c'};
        map['3'] = {'d','e','f'};
        map['4'] = {'g','h','i'};
        map['5'] = {'j','k','l'};
        map['6'] = {'m','n','o'};
        map['7'] = {'p','q','r','s'};
        map['8'] = {'t','u','v'};
        map['9'] = {'w','x','y','z'};
    
        vector<string> res;    
        generate(map, digits, 0 , "", res);
        
        return res;
    }


int main(){


	string digits = "234";
	vector<string> res = letterCombinations(digits);

	for(auto x : res){
		cout << x << " ";
	}
	cout << "\n";

	return 0;
}
