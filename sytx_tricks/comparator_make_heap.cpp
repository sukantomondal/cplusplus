#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare (int a , int b){
	return a<b;
}

// comparator function to make min heap
struct greaters{
  bool operator()(const long& a,const long& b) const{
    return a>b;
  }
};


int main(){

	vector<int> v = {1,34,6,12,43,29,0};

	make_heap(v.begin(), v.end());  // by default max heap

	cout << v.front() << "\n";  // print 43 as the maximum number in the array


	make_heap(v.begin(),v.end(),greaters());
	cout << v.front() << "\n";

	while(v.size()!=0){
		cout << v.front() << " ";
		pop_heap(v.begin(),v.end()); v.pop_back();
		make_heap(v.begin(),v.end(),greaters());  // heapify
	}
	cout<< "\n";

	/*for(int x : v){
		cout << x << "\n";
	}
	*/
	return 0;
}
