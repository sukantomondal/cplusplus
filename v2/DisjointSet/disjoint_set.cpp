/* Array implementation of disjoint set */

#include<iostream>
#include<vector>
using namespace std;

class Disjointset {
	public:
	int size;
	vector<int> parent;
	vector<int> rank;
	Disjointset(int size){	
		this->size = size;
		for (int i = 0; i < size; i++) {
			parent.push_back(i);
			rank.push_back(0);
		}
	}

	int distinct_group() {
		int count = 0;
		for(int i = 0; i< size; i ++) {
			if(parent[i] == i) {
				count++;
			}
		}
		return count;
	}

	int find (int x) {

		if (parent[x] != x) {
			return find(parent[x]);
		}
		return parent[x];
	}

	void _union (int x , int y) {

		int xroot = find (x);
		int yroot = find (y);

		if (xroot == yroot)
			return;
	      	if (rank[xroot] < rank[yroot]) {
			parent[xroot] = yroot;
		} else if (rank[yroot] < rank[xroot]) {
			parent[yroot] = xroot;
		} else {
			parent[xroot] = yroot;
		       	rank[yroot] = rank[yroot] + 1; 	
		}	
	}

};

int main() {	
	Disjointset ds = Disjointset(20);
	cout << ds.size << "\n";
	cout << "\ndistinct group" << ds.distinct_group() << "\n";

	ds._union(0,4);
	ds._union(4,10);
	ds._union(4,11);
	ds._union(10,5);

	cout << "\nAfter union" << ds.distinct_group() << "\n";
	cout << "\nFind element root element " << ds.find(5) << "\n";

	return 0;
}

