/*The Stock Span Problem
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate span of stock’s price for all n days. 
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}

https://www.geeksforgeeks.org/the-stock-span-problem/

*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> stock_span(vector<int> arr){

	stack<int> stk;
	vector<int> span(arr.size());

	for(int i=0; i < arr.size(); i++){
		while(!stk.empty() && arr[stk.top()] <= arr[i]){
			stk.pop();
		}
	

		if(stk.empty()){
			span[i] = i+1;
		}else{
			span[i] = i-stk.top();
		}

		stk.push(i);
	}

	return span;
}

void print(vector<int> arr){

	for(auto x : arr)
		cout << x << " ";
	cout << "\n";
}

int main(){


	vector<int> arr =  {100, 80, 60, 70, 60, 75, 85};


	vector<int>span = stock_span(arr);

	print (span);


	return 0;
}
