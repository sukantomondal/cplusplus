/* 0-1 BFS (Shortest Path in a Binary Weight Graph)
Given a graph where every edge has weight as either 0 or 1. A source vertex is also given in the graph. Find the shortest path from source vertex to every other vertex.
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node{
	int to, weight;
};

struct dqnode{
	int from, to, weight;
};

void add_edge(vector<vector<node>> &adj_list,int u, int v, int weight){

	adj_list[u].push_back({v,weight});
	adj_list[v].push_back({u,weight});
}

void shortest_path(vector<vector<node>> adj_list,int src){

	int v = adj_list.size(); // graph size;
	vector<int> dist(v,INT8_MAX);
	dist[src] = 0;

	deque<int> dq;
	dq.push_front(src);

	while(!dq.empty()){

		int curr = dq.front();
		dq.pop_front();

		for(int i = 0 ; i < adj_list[curr].size(); i++){

			if(dist[adj_list[curr][i].to] > adj_list[curr][i].weight + dist[curr]){

				dist[adj_list[curr][i].to] = adj_list[curr][i].weight + dist[curr];

				if(adj_list[curr][i].weight == 0){
					dq.push_front(adj_list[curr][i].to);
				}
				else{
					dq.push_back(adj_list[curr][i].to);
				}
			}
		}
	}


	for(int x : dist){

		cout << x << " ";
	}

	cout << "\n";
}



int main(){

	int v = 9; // size of the graph
	vector<vector<node>>adj_list(v);

	add_edge(adj_list,0, 1, 0);
    	add_edge(adj_list,0, 7, 1);
    	add_edge(adj_list,1, 7, 1);
    	add_edge(adj_list,1, 2, 1);
    	add_edge(adj_list,2, 3, 0);
    	add_edge(adj_list,2, 5, 0);
    	add_edge(adj_list,2, 8, 1);
    	add_edge(adj_list,3, 4, 1);
    	add_edge(adj_list,3, 5, 1);
    	add_edge(adj_list,4, 5, 1);
    	add_edge(adj_list,5, 6, 1);
    	add_edge(adj_list,6, 7, 1);
    	add_edge(adj_list,7, 8, 1);

	shortest_path(adj_list,0);

	return 0;
}
