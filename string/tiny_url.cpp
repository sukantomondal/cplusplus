/*How to design a tiny URL or URL shortener?
How to design a system that takes big URLs like “https://www.geeksforgeeks.org/count-sum-of-digits-in-numbers-from-1-to-n/” and converts them into a short 6 character URL. It is given that URLs are stored in the database and every URL has an associated integer id.

One important thing to note is, the long URL should also be uniquely identifiable from the short URL. So we need a Bijective Function
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string id_to_tiny_url(long long int n){

	string char_map = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	string short_url;

	while(n){
		short_url.push_back(char_map[n%62]);
		n=n/62;	
	}

	reverse(short_url.begin(),short_url.end());

	//cout << short_url << "\n";
	//cout << "\n";

	return short_url;
}


int short_url_to_id(string s){
	int id = 0;
	for(int i = 0; i < s.length(); i++){

		if(s[i]>= 'a' && s[i] <= 'z'){
			id = id*62 + s[i] -'a';
		}
		if(s[i]>= 'A' && s[i] <= 'Z'){
			id = id*62 + s[i] -'A' +26;
		}
		if(s[i] >= '0' && s[i] < '9'){
			id = id*62 + s[i] - '0' +52;
		}
	}
	return id;
}

int main(){

	long long int i = 1234;
	string short_url = id_to_tiny_url(i);

	cout << short_url << "\n";

	int id = short_url_to_id(short_url);

	cout << id << "\n";

	return 0;
}
