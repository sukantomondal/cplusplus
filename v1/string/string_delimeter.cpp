#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> explode(string s, string del){

	vector<string> res;
	size_t pos = 0;
	while((pos = s.find(del)) != string::npos){
		string token = s.substr(0,pos);
		res.push_back(token);
		s.erase(0,pos+del.length());
	}
	res.push_back(s);
	return res;

}

string strip( string s ){

	string res = "";
	int n = 0;

	for(int i = 0 ; i < s.length(); i++){		
		if(s[i] == ' '){
			n++;
			if(n==1 && i-1>=0 && s[i-1] != ' ')
				res+= s[i];	
		}else{
			n=0;
			res += s[i];
		}
	}

	return res;
}

int main(){

	vector<string> res  = explode("str is ss___ a good auu string", " ");


	 cout << strip("    sdd   dd ddd ddd                 888    ") << "\n";


	for (auto x : res){
		cout << x << "\n" ;
	}
	return 0;
}
