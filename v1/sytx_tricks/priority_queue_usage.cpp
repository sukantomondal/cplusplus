/* Author : Sukanto Mondal */

/* priority queue usage */

#include <iostream>
#include <queue>
using namespace std;

void print_pq(priority_queue <int> pq){

	priority_queue <int> t = pq;
	
	while(!t.empty()){
	cout<< t.top() << " ";
	t.pop();
	}
	cout << "\n";
}

int main (){

	priority_queue <int> pq;
	pq.push(1);
	pq.push(10);
	pq.push(12);
	pq.push(-1);
	pq.push(0);

	cout << "The priority queue is: \n";
	print_pq(pq);
	cout << "The queue size is : " << pq.size() << "\n"; 
	return 0;
}
