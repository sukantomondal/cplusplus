/*Dijkstra’s Algorithm
 *
 * Dijkstra’s shortest path algorithm | Greedy Algo-7
Given a graph and a source vertex in the graph, find shortest paths from source to all vertices in the given graph.
Dijkstra’s algorithm is very similar to Prim’s algorithm for minimum spanning tree. Like Prim’s MST, we generate a SPT (shortest path tree) with given source as root. We maintain two sets, one set contains vertices included in shortest path tree, other set includes vertices not yet included in shortest path tree. At every step of the algorithm, we find a vertex which is in the other set (set of not yet included) and has a minimum distance from the source.

Below are the detailed steps used in Dijkstra’s algorithm to find the shortest path from a single source vertex to all other vertices in the given graph.
Algorithm
1) Create a set sptSet (shortest path tree set) that keeps track of vertices included in shortest path tree, i.e., whose minimum distance from source is calculated and finalized. Initially, this set is empty.
2) Assign a distance value to all vertices in the input graph. Initialize all distance values as INFINITE. Assign distance value as 0 for the source vertex so that it is picked first.
3) While sptSet doesn’t include all vertices
….a) Pick a vertex u which is not there in sptSet and has minimum distance value.
….b) Include u to sptSet.
….c) Update distance value of all adjacent vertices of u. To update the distance values, iterate through all adjacent vertices. For every adjacent vertex v, if sum of distance value of u (from source) and weight of edge u-v, is less than the distance value of v, then update the distance value of v.

https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
*/

#include<iostream>
#include<vector>
using namespace std;



int min_dist(vector<bool> spath, vector<int> dist){


	int min = INT8_MAX;
	int min_index = -1;

	for(int i = 0 ; i < dist.size(); i++){

		if(spath[i] == false && dist[i] < min){
			min = dist[i];
			min_index = i;
		}
	}

	return min_index;
}

void shortest_path(vector<vector<int>> graph){

	int no_of_vertices = graph.size();

	vector<bool> spath (no_of_vertices , false);
	vector<int> dist (no_of_vertices, INT8_MAX);

	
	spath[0] = false;
	dist [0] =0; 

	for(int count = 0 ; count < no_of_vertices -1 ; count ++){

		int min_dist_node = min_dist(spath,dist);

		for(int v = 0 ; v < no_of_vertices ; v++){

			if(graph[min_dist_node][v] && spath[v] == false && dist[min_dist_node] + graph[min_dist_node][v] < dist[v]){

				dist[v] = dist[min_dist_node] + graph[min_dist_node][v];
			}
		}

		spath[min_dist_node] = true;
	}

	for(int i = 0 ; i < no_of_vertices; i++){

		cout << i << "    " << dist[i] << "\n";
	}
}

int main(){


	vector<vector<int>> graph = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                      {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                      {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                      {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                     }; 


	shortest_path(graph);


	return 0;
}
