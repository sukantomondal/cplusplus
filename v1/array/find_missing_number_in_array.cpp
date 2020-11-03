#include<iostream>
#include<vector>
using namespace std;

/*Find the missing number in the array which contains a series of consecutive numbers in range from 1 to n. Use summation formula for natural numbers 1 to n. We can also use the XOR operation.
 *
 */


int find_missing_number(vector<int> arr,int n){

	int r=arr[0];
	
	for(int i = 1; i < arr.size(); i++){
		r=r^arr[i];
	}

	int a = 1;
	for(int i=2; i<=n; i++)
		a=a^i;
	return a^r;
}

int main(){

	vector<int> arr = {1,2,4,5,6};
	
	cout <<"Missing number :"<<find_missing_number(arr,6) << "\n";

	return 0;
}
