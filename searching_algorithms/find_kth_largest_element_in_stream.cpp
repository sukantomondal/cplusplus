/*K’th largest element in a stream
Given an infinite stream of integers, find the k’th largest element at any point of time.
Example:

Input:
stream[] = {10, 20, 11, 70, 50, 40, 100, 5, ...}
k = 3

Output:    {_,   _, 10, 11, 20, 40, 50,  50, ...}
Extra space allowed is O(k).

*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct compare{
	bool operator()(int a , int b){
		return a>b;
	}
};


void print_kth_largest_number(int k , int n, priority_queue<int, vector<int>, compare> &pq){

	if(pq.size() < k){
		pq.push(n);
		//cout << "nothing to print\n";
	}
	else{
		if(pq.top() < n){
			pq.pop();
			pq.push(n);
		}
	}

	if(pq.size()>=k)
		cout <<"Kth largest is : " <<pq.top() << "\n";

}

void kth_largest(int k){
	
	int n ;
	priority_queue<int, vector<int>, compare> pq;

	while (1){
		cout << "Enter the next number is the stream \n";
		cin >> n;
		if(n==1000){ // this is just for to exit from the stream
			cout << "Stream ended \n";
			break;
		}

		print_kth_largest_number(k,n,pq);
	}
}

int main(){

	kth_largest(3);

	return 0;
}
