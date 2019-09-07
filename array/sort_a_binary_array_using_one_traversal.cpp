/*Sort a binary array using one traversal
Given a binary array, sort it using one traversal and no extra space.

Examples :

Input : 1 0 0 1 0 1 0 1 1 1 1 1 1 0 0 1 1 0 1 0 0 
Output : 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1

Input : 1 0 1 0 1 0 1 0 
Output : 0 0 0 0 1 1 1 1

*/

#include<iostream>
#include<vector>
using namespace std;

void sort (vector<int> &arr){

	int i = 0;
	int l = 0;

	while(i< arr.size()){
		if(arr[i] == 1){
			i++;
		}else{
			swap(arr[l],arr[i]);
			i++; l++;
		}
	}
}

void print(vector<int> arr){
	for(auto x : arr){
		cout << x << " ";
	}
	cout << "\n";
}
int main(){
	vector<int> arr = {1,0,0,1,0,0,1,1,0,0,1,1,1};
	sort(arr);
	print(arr);
	return 0;
}
