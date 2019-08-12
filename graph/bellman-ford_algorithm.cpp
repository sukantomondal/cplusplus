/*Bellman–Ford Algorithm | DP-23
Given a graph and a source vertex src in graph, find shortest paths from src to all vertices in the given graph. The graph may contain negative weight edges.
We have discussed Dijkstra’s algorithm for this problem. Dijkstra’s algorithm is a Greedy algorithm and time complexity is O(VLogV) (with the use of Fibonacci heap). Dijkstra doesn’t work for Graphs with negative weight edges, Bellman-Ford works for such graphs. Bellman-Ford is also simpler than Dijkstra and suites well for distributed systems. But time complexity of Bellman-Ford is O(VE), which is more than Dijkstra.

*/

#include<iostream>
#include<vector>
#include<list>

using namespace std;

struct edge{
	int to,weight;
};


void addEdge (vector<list<edge>> &adj_list, int u, int v, int weight){

	edge e = {v,weight};
	adj_list[u].push_back(e);
}

void shortest_path(vector<list<edge>> adj_list){

	int no_of_vertices = adj_list.size();
	vector<int> dist (no_of_vertices, INT8_MAX);

	dist[0] = 0;

	
	for(int count = 0 ; count < no_of_vertices-1; count++ ){

	
		for(int i = 0 ; i < adj_list.size(); i++){

			for(edge e : adj_list[i]){
	
				cout << i << "---" << e.to << "  " << e.weight << "\n";
	
				if(dist[i] + e.weight < dist[e.to]){
					dist[e.to] =  dist[i] + e.weight;
				}
			}
		}

		for(auto x : dist)
			cout << x << " ";

		cout << "\n";
	}

}

int main(){

	int no_of_vertices = 5;
	vector<list<edge>> adj_list(no_of_vertices);

	addEdge(adj_list,0,1,-1);
	addEdge(adj_list,0,2,4);
	addEdge(adj_list,1,2,3);
	addEdge(adj_list,1,3,2);
	addEdge(adj_list,1,4,2);
	addEdge(adj_list,3,1,1);
	addEdge(adj_list,3,2,5);
	addEdge(adj_list,4,3,-3);

	shortest_path(adj_list);

	return 0;
}
