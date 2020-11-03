/*Program to generate all possible valid IP addresses from given string
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

Examples :

Input : 25525511135
Output : [“255.255.11.135”, “255.255.111.35”]
Explanation: 
These are the only valid possible
IP addresses.

Input : "25505011535"
Output : []
Explanation : 
We cannot generate a valid IP
address with this string. 
*/


#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

bool is_valid(string s){
        if(s.length() == 0)
            return false;
        if(s.length()>=2){
            if(s[0] == '0')
                return false;
        }
        stringstream g(s);
        int x ;
        g>>x;
        return (x<=255);
}

void ip_generate(string s, vector<string> ip, vector<string> &result){

        if(s.size()== 0 && ip.size()==4){
                string res;
                for(int i = 0 ; i < ip.size() -1 ; i++){
                    res +=ip[i]+'.';
                }
                res +=ip[ip.size()-1];
                result.push_back(res);
        }

        if(ip.size()== 4 || s.size() == 0){
                return;
        }

        for(int i = 0 ; i< 3 && i < s.length(); i++){

                string sub_str1 = s.substr(0,i+1);
                string sub_str2 = s.substr(i+1, s.length()-i);
                if(is_valid(sub_str1)){
                        vector<string> ip_call;
                        for(auto x : ip){
                                ip_call.push_back(x);
                        }
                        ip_call.push_back(sub_str1);
                        ip_generate(sub_str2, ip_call, result);
                }
        }
}


int main(){

	string s = "25525511135";

	vector<string> result;
	vector<string> ip;
	ip_generate(s,ip, result);

	for(auto x : result){
		cout << x << "\n";
	}

	return 0;
}
