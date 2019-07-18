#include<iostream>
#include<vector>

using namespace std;


/*Zig Zag array is an array in which every element is less than and greater than the next element alternatively. Every element is either greater than or less than its neighbours.
 */


void zig_zag(vector <int> &arr){

	bool flag = 0; int i = 0;
	while(i < (arr.size()-1)){

		if(!flag && arr[i] > arr[i+1])
			swap(arr[i],arr[i+1]);
		if(flag && arr[i] < arr[i+1])
			swap(arr[i],arr[i+1]);
		flag = !flag;

		i++;
	};
}


void print_array(vector<int> &arr){

	for (auto x: arr)
		cout<<x << " ";

	cout << "\n";
}


int main(){


	vector<int> arr = {3,4,6,2,1,8,9};

	print_array(arr);
	zig_zag(arr);
	print_array(arr);

	return 0;
}
