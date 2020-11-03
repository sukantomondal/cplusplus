/*Generate Parentheses
 *
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/


#include<iostream>
#include<vector>
using namespace std;

void generate (int left, int right, int n, string str, vector<string> &result){
        
        if(left == right && str.length() == n*2){
            result.push_back(str);
            return;
        }
        
        if(left < n){
            generate(left+1, right, n, str+'(', result);
        }
        if(left > right){
            generate(left, right+1, n, str+')', result);
        }
            
}

int main(){

	vector<string> res;
	int n = 3; // how many pair;
        generate(1,0,n,"(", res);

	for(auto x : res){
		cout << x << " ";
	}

	cout << "\n";

	return 0;
}
