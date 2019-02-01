/* Author : Sukanto Mondal */


#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
void remove_duplicate(vector<int> &arr){
	unordered_map<int,bool> temp;

	for(int i = 0; i< arr.size(); i++){

		if(temp.find(arr[i]) != temp.end()){
		}else{
			temp[arr[i]]= true;
			cout << arr[i] << " ";
		}
	}

	cout << "\n";
}



void print_array (vector<int> arr){
	for(int i = 0 ; i< arr.size(); i++){
		cout << arr[i] << " ";
	}

	cout << "\n";
}

int main (){
	vector <int> arr =  {1,4,5,9,3,4,5,2,6,1,3,3,4,2,2};

	cout << "The given array is : \n";
	print_array(arr);

	cout << "The array after removing the duplicate \n";

	remove_duplicate(arr);
	return 0;
}
