/*Author : Sukanto Mondal */


/*Given an array, print the Next Smaller Element (NSE) for every element. The Smaller smaller Element for an element x is the first smaller element on the right side of x in array. Elements for which no smaller element exist (on right side), consider next smaller element as -1.

Examples:
a) For any array, rightmost element always has next smaller element as -1.
b) For an array which is sorted in increasing order, all elements have next smaller element as -1.
c) For the input array [4, 8, 5, 2, 25}, the next smaller elements for each element are as follows.

Element       NSE
   4      -->   2
   8      -->   5
   5      -->   2
   2      -->   -1
   25     -->   -1

d) For the input array [13, 7, 6, 12}, the next smaller elements for each element are as follows.

  Element        NSE
   13      -->    7
   7       -->    6
   6       -->    -1
   12     -->     -1
*/


#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main (){

	vector<int> arr = {4,8,5,2,25};
	stack<int> st;

	st.push(arr[0]);

	for(int i = 0; i< arr.size(); i++){
		if(st.empty())
			st.push(arr[i]);

		while(!st.empty() && st.top() > arr[i]){
			cout << st.top() << "-->" << arr[i] << "\n";
			st.pop();
		}

		st.push(arr[i]);
	}

	while(!st.empty()){
		cout<< st.top() <<"-->" << -1 << "\n";
		st.pop();
	}

	return 0;
}
