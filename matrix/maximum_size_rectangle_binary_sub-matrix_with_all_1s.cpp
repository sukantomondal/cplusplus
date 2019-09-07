/*Maximum size rectangle binary sub-matrix with all 1s
Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s.
Example:

Input :   0 1 1 0
          1 1 1 1
          1 1 1 1
          1 1 0 0

Output :  1 1 1 1
          1 1 1 1
*/



#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int max_area_hist(vector<int> hist){
	
	stack<int> stk;
	int max_area = 0, area, index;

	int i = 0; // here index is very important

	for(i = 0 ; i < hist.size(); i++){

		if(stk.empty() || hist[stk.top()]<= hist[i]){
			stk.push(i);
		}else{

			while(!stk.empty() && hist[stk.top()] > hist[i]){
				if(stk.size()==1){
					area = i * hist[stk.top()];
				}else{
					area = (i - stk.top()) * hist[stk.top()];
				}
				max_area = max(max_area, area);
				stk.pop();
			}
			stk.push(i);
			
		}

	}

	if(!stk.empty()){

		while(!stk.empty()){
			if(stk.size() == 1){
				area = i * hist[stk.top()];
			}else{
				area = (i-stk.top()) * hist[stk.top()];
			}

			max_area = max (max_area, area);
			stk.pop();
		}
	}

	return max_area;
}


int maximum_area(vector<vector<int>> arr){

	int max_area = 0;

	vector<int> hist(arr[0].size(),0);

	for(int i = 0 ; i < arr.size(); i++){

		for(int j = 0 ; j < arr[0].size(); j++){
			if(arr[i][j]!=0){
				hist[j]++;
			}else{
				hist[j]=0;
			}
		}

		max_area = max(max_area,max_area_hist(hist));

	}

	return max_area;
}



int main(){

	vector<vector<int>> arr = {{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
	cout << maximum_area(arr);
	//
	//cout << max_area_hist({2,1,2,1});

	return 0;
}
