#include<iostream>
#include<vector>
using namespace std;


void segregate_positive_nagative_numbers(vector<int> & arr){

	int i = 0, j = arr.size()-1;
	while(true){

		while(arr[i] < 0 && i < j)
			i++;
		while(arr[j] > 0 && i < j)
			j--;
		if(i<j){
			swap(arr[i],arr[j]); i++; j--;
		}
		else
			break;

	}
}

void print_array(vector<int> & arr){

	for(int i = 0; i < arr.size()-1; i++){

		cout << arr[i] << " ";
	}

	cout << "\n";
}

int main(){

	vector<int> arr = {-1,2,-4,-3,4,5};
	segregate_positive_nagative_numbers(arr);

	print_array(arr);
	return 0;
}
