#include<iostream>
#include<vector>
using namespace std;

/* segregate 0's 1's and 2's togather */




void dutch_national_flag(vector<int> & arr){



	int low = 0, mid = 0, high = arr.size()-1;

	while(mid <= high){

		switch(arr[mid]){

			case 0:
				swap(arr[low],arr[mid]);
				low++; mid++;
				break;
			case 1:
				mid++;
				break;
			case 2:
				swap(arr[high],arr[mid]);
				high--;
				break;
		}



	}

}



void print_array(vector<int> & arr){

	for (int i = 0; i < arr.size(); i++){

		cout << arr[i] << " ";
	}

	cout << "\n";
}

int main(){

	vector<int> arr = {0,1,2,1,0};
	print_array(arr);
	dutch_national_flag(arr);
	print_array(arr);
	return 0;
}
