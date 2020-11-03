/* Author : Sukanto Mondal*/

/*sorting Usage*/

#include<iostream>
#include<algorithm>
using namespace std;
#define N 10


struct st {
	int index;
	char val;
};

void simple_sort(int arr[N]){
	sort(arr,arr+N);
}

bool comparable(st obj1,st obj2){
	return (obj1.index < obj2.index);
}

void object_sort(st st_arr[N]){
	// sort the object using comparable;
	sort(st_arr,st_arr+N,comparable);
}

void print_array(int arr[N]){

	for(int i = 0; i<N; i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
	
}


void print_obj_array(st st_arr[N]){
	for(int i= 0; i<N; i++){
		cout<<"{"<<st_arr[i].index << "," << st_arr[i].val << "}  "; 
	}
	cout << "\n";

}

int main(){
	int arr[N] = {5,2,4,1,8,3,2,7,0,-1};
	cout << "The array is:\n";
	print_array(arr);
	simple_sort(arr);
	cout << "The sorted array is: \n"; 
	print_array(arr);
        	
	st st_arr[N] = {{1,'a'},{2,'w'},{-1,'z'},{0,'p'},{7,'q'},{4,'r'},{-3,'k'},{5,'r'},{6,'t'},{-10,'v'}};
	cout << "The object array is: \n";
	print_obj_array(st_arr);
	object_sort(st_arr);
	cout << "The Sorted object array is:\n";
	print_obj_array(st_arr);

	return 0;
}
