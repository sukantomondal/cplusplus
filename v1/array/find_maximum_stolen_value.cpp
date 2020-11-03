/* Author : Sukanto Mondal */

/*
Find maximum possible stolen value from houses

There are n houses build in a line, each of which contains some value in it. A thief is going to steal the maximal value of these houses, but he can’t steal in two adjacent houses because owner of the stolen houses will tell his two neighbour left and right side. What is the maximum stolen value.
Examples:

Input  : hval[] = {6, 7, 1, 3, 8, 2, 4}
Output : 19
Thief will steal 6, 1, 8 and 4 from house.

Input  : hval[] = {5, 3, 4, 11, 2}
Output : 16
Thief will steal 5 and 11
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int find_max(vector<int> &arr){
	if(arr.size() ==0)
		return 0;
	if(arr.size()==1)
		return arr[0];
	if(arr.size()==2)
		return max(arr[0],arr[1]);

	int max1 = 0;
	int max2 = max(arr[0],arr[1]);

	int new_max = 0;

	for(int i = 2; i< arr.size() ; i++){
		 new_max = max(max1+arr[i],max2);
		 max1= max2;
		 max2=new_max;
	}

	return new_max;
}


int main(){

	vector<int>arr = {6,7,1,3,8,2,4};
	cout << "The max posible stolen value is :" << find_max(arr) << "\n";
	return 0;

}
