/*Prim’s Minimum Spanning Tree (MST)*/

/*Algorithm
1) Create a set mstSet that keeps track of vertices already included in MST.
2) Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE. Assign key value as 0 for the first vertex so that it is picked first.
3) While mstSet doesn’t include all vertices
….a) Pick a vertex u which is not there in mstSet and has minimum key value.
….b) Include u to mstSet.
….c) Update key value of all adjacent vertices of u. To update the key values, iterate through all adjacent vertices. For every adjacent vertex v, if weight of edge u-v is less than the previous key value of v, update the key value as weight of u-v

https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/

*/


#include<iostream>
#include<vector>
using namespace std;


int min_key(vector<int> mst_set, vector<int> key){

	int min = INT8_MAX;
	int min_index = -1; // min node

	for(int i = 0 ; i < key.size(); i++){

		if(mst_set[i] == false && key[i] < min){
			min = key[i];
			min_index = i;
		}
	}

	return min_index;
}



void mst(vector<vector<int>> graph){

	int no_of_vertices = graph.size();

	vector<int> mst_set(no_of_vertices,false);
	vector<int> key(no_of_vertices, INT8_MAX);
	vector<int> parent(no_of_vertices);

	key[0] = 0; // starting from 0 node
	parent[0] =-1;

	for(int count = 0 ; count < no_of_vertices-1; count++){
		
		int min_node = min_key(mst_set,key);

		for(int v = 0; v < no_of_vertices ; v++){

			if(graph[min_node][v] && mst_set[v] == false && graph[min_node][v] < key[v]){
				key[v] = graph[min_node][v];
				parent[v] = min_node;
			}
		}

		mst_set[min_node] = true;
	}

	for(int i = 1 ; i < no_of_vertices; i++){

		cout << parent[i] << "---" << i << "  " <<key[i] << "\n";
	}
}


int main(){

	vector<vector<int>> graph = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

	mst(graph);

	return 0;
}
