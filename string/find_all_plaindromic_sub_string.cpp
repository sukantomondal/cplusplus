/*Find all palindromic sub-strings of a given string | Set 2
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;



void find_plaindrom(string s){


	vector<string> all_plaindrom;

	for(float pivot=0; pivot<s.length(); pivot+=0.5){

		float radius = pivot - (int) pivot;

		while(pivot+radius < s.length() && pivot - radius >= 0 && s[(int) (pivot + radius)] == s[(int) (pivot-radius)]){

			int start = (int) (pivot -radius);
			int end = (int) (pivot + radius);

			cout <<  s.substr(start, end-start+1) << "\n";
			//cout << pivot << radius << " "<< start << end << "\n";
			all_plaindrom.push_back(s.substr(start, end-start+1));
			radius+=1;
		}
	}

	cout << all_plaindrom.size() << "\n";


}

int main(){

	//string s = "geeksforgeeks";
	string s = "aaaa";

	find_plaindrom(s);
	return 0;
}
