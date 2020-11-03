/* Author : Sukanto Mondal */

// Set typically implement a binary searh tree

// find the kth smallest element using binary tree

#include <iostream>
#include <set>

using namespace std;

void print_set(set<int> s){

	set <int> :: iterator it;

	for(it = s.begin() ; it != s.end() ; ++it){
		cout<< *it << " ";
	}

	cout << "\n";
}

// print kth smallest element using binary tree.

void print_kth_smallest(set<int>s, int k){
	
	set<int> :: iterator it;
	it = next(s.begin(),(k-1));
	cout<< *it << "\n";
}

int main (){
	// A set is a binary search tree. NlogN insertation
	set <int> s;
	s.insert(1);
	s.insert(0);
	s.insert(10);
	s.insert(-1);
	s.insert(4);

	cout << "The set contains: \n";
	print_set(s);

	cout << "The third smallest element is : \n";
	print_kth_smallest(s,3);  

	return 0;
}
