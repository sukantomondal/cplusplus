/* longest incresing subsequence */


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void lis(vector<int> arr){
	vector<int> len(arr.size(),1);
	vector<int> seq(arr.size(),-1);

	for(int i = 1; i < arr.size(); i++){

		for(int j = 0 ; j < i ; j++){

			if(arr[j] < arr[i]){
				//len[i] = max(len[i], len[j]+1);
				//
				if(len[j]+1 >= len[i]){
					len[i] = len[j]+1;
					seq[i] = j;
				}
			}
		}
	}


	//sort(len.begin(),len.end());
	//
	
	int max = 0;
	int max_index = 0;

	for(int i = 0 ; i < arr.size(); i++){

		if(len[i]>max){
			max = len[i];
			max_index = i;
		}
	}
	cout << len[max_index] << "\n";

	// length array
	for(auto x : len){

		cout << x << " ";
	}
	cout << "\n";

	// sequence array
	for(auto x : seq){

		cout << x << " ";
	}

	cout << "\n";

	while(max_index >= 0){
		cout << arr[max_index] << " ";
		max_index = seq[max_index];
	}
	cout << "\n";
}

int main(){

	vector<int> arr = {30, 10, 2, 1, 20,30,40,-1};
	lis(arr);

	return 0;
}
