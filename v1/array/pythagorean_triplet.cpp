/*Pythagorean Triplet in an array
Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2.
Example:

Input: arr[] = {3, 1, 4, 6, 5}
Output: True
There is a Pythagorean triplet (3, 4, 5).

Input: arr[] = {10, 4, 6, 12, 5}
Output: False
There is no Pythagorean triplet.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;


bool find_triplet(vector<int> arr){

	for(int i = 0 ; i< arr.size(); i++)
		arr[i] = arr[i]*arr[i];

	sort(arr.begin(),arr.end()); // sort array


	for(int i = arr.size()-1; i >=2; i--){

		int l = 0, r = i-1;

		while(l<r){

			if(arr[i] == arr[l]+arr[r]){
				cout << arr[i] << " "<< arr[l] <<"  " <<arr[r] << "\n";
				return true;
			}

			if(arr[i] > arr[l] + arr[r]){
				l++;
			}else{
				r--;
			}
		}
	}

	return false;

}

bool find_triplet_using_hash(vector<int>arr){


	unordered_set<int> hash;
	for(int i = 0 ; i< arr.size(); i++){
		arr[i] = arr[i]*arr[i];
		hash.insert(arr[i]);
	}


	for(int i = 0 ; i < arr.size(); i++){

		for(int j = i+1 ; j < arr.size(); j++ ){

			int tmp = arr[i] + arr[j];

			auto it = hash.find(tmp);

			if(hash.find(tmp) != hash.end()){

				cout << arr[i] << " " << arr[j] << " " << *it << "\n";  
				return true;
			}
		}
	}

	return false;
}

int main(){
	vector<int> arr = {3, 1, 4, 6, 5};
	//
	//vector<int> arr=  {10, 4, 6, 12, 5};
	if(find_triplet_using_hash(arr)){
		cout << "Triplet found" << "\n";
	}
	else{

		cout << "Tiplet not found" << "\n";
	}
	return 0;
}
