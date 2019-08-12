/*Disjoint Set (Or Union-Find) | Set 1 (Detect Cycle in an Undirected Graph)
A disjoint-set data structure is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets. A union-find algorithm is an algorithm that performs two useful operations on such a data structure:

Find: Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.

Union: Join two subsets into a single subset.

https://www.geeksforgeeks.org/union-find/

*/

#include<iostream>
#include<vector>
using namespace std;

struct Edge{
	int u;
	int v;
};

Edge get_edge(int u , int v){
	Edge edge = {u,v};
	return edge;
}


int find(vector<int> &parent, int v){

	if(parent[v] == -1){
		return v;
	}
	return find(parent,parent[v]);	
}

void Union(vector<int>&parent, int v1, int v2){

	int x = find (parent,v1);
	int y = find (parent,v2);;

	if(x!=y){
		parent[x] = y;
	}
}


// we can do union and find in another way so that it will not take liner time


bool detect_cycle(vector<Edge> graph, int no_of_vertices){

	vector<int> parent(no_of_vertices,-1);

	for(int i = 0 ; i < graph.size(); i++){

		int x = find(parent, graph[i].u);
		int y = find(parent, graph[i].v);

		if(x==y){
			return true; 
		}
		Union(parent,graph[i].u,graph[i].v);

	}


	return false;
}

int main(){
	//The graph is represented as an array of edge
	
	int no_of_vertices = 3;

	vector<Edge> graph;
	graph.push_back(get_edge(0,1));
	graph.push_back(get_edge(0,2));
	graph.push_back(get_edge(1,2));
	
	cout << "Is cycle: " <<detect_cycle(graph, no_of_vertices) << "\n";
	return 0;
}
