/*Program to replace a word with asterisks in a sentence
For the given sentence as input, censor a specific word with asterisks ‘ * ‘.

Example :

Input : word = “computer”
text = “GeeksforGeeks is a computer science portal for geeks. People who love computer and computer codes can contribute their valuables/ideas on computer codes/structures on here.”
Output : GeeksforGeeks is a ******** science portal for geeks. People who love ******** and ******** codes can contribute their valuables/ideas on ******** codes/structures on here.
*/


#include<iostream>
#include<vector>
using namespace std;


void censor(string txt , string pat){

	int n = pat.length();
	int m = txt.length();

	for (int i = 0; i <= m-n; i++){
		string sub_txt = txt.substr(i,n);
		if(sub_txt.compare(pat)==0){
			for (int j = i ; j < i+n ; j++)
				txt[j] = '*';
		}
	}
	cout << txt << "\n";
}	


int main(){
	
	string txt = "GeeksforGeeks is a computer science portal for geeks. People who love computer and computer codes can contribute their valuables/ideas on computer codes/structures on here.";

	string pat = "computer";

	censor(txt,pat);

	return 0;	
}
