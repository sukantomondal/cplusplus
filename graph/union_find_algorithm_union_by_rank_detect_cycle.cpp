/*Disjoint Set (Or Union-Find) | Set 1 (Detect Cycle in an Undirected Graph)
A disjoint-set data structure is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets. A union-find algorithm is an algorithm that performs two useful operations on such a data structure:

Find: Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.

Union: Join two subsets into a single subset.

https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/

*/


#include<iostream>
#include<vector>
using namespace std;

struct Edge{
	int u;
	int v;
};

struct setnode{
	int parent;
	int rank;
};

Edge get_edge(int u , int v){
	Edge edge = {u,v};
	return edge;
}


int find(vector<setnode> set, int v){

	if(set[v].parent != v)
		set[v].parent = find(set,set[v].parent);
	return set[v].parent;
}

void Union(vector<setnode>&set, int v1, int v2){

	int xroot = find (set,v1);
	int yroot = find (set,v2);;

	if(set[xroot].rank < set[yroot].rank){
		set[xroot].parent = yroot;
	}else if(set[xroot].rank > set[yroot].rank){
		set[yroot].parent = xroot;
	}
	else{
		set[xroot].parent = yroot;
		set[yroot].rank++;
	}
}


// we can do union and find in another way so that it will not take liner time


bool detect_cycle(vector<Edge> graph, int no_of_vertices){

	vector<setnode> set(no_of_vertices);

	for(int v = 0 ; v< no_of_vertices; v++){
		set[v].parent = v;
		set[v].rank = 0;
	}	

	for(int i = 0 ; i < graph.size(); i++){

		int x = find(set, graph[i].u);
		int y = find(set, graph[i].v);

		if(x==y){
			return true; 
		}
		Union(set,graph[i].u,graph[i].v);

	}


	return false;
}

int main(){
	//The graph is represented as an array of edge
	
	int no_of_vertices = 3;

	vector<Edge> graph;
	graph.push_back(get_edge(0,1));
	graph.push_back(get_edge(0,2));
	//graph.push_back(get_edge(1,2));
	
	cout << "Is cycle: " <<detect_cycle(graph, no_of_vertices) << "\n";
	return 0;
}
