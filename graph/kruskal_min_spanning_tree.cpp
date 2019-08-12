/*What is Minimum Spanning Tree?
Given a connected and undirected graph, a spanning tree of that graph is a subgraph that is a tree and connects all the vertices together. A single graph can have many different spanning trees. A minimum spanning tree (MST) or minimum weight spanning tree for a weighted, connected and undirected graph is a spanning tree with weight less than or equal to the weight of every other spanning tree. The weight of a spanning tree is the sum of weights given to each edge of the spanning tree.

How many edges does a minimum spanning tree has?
A minimum spanning tree has (V – 1) edges where V is the number of vertices in the given graph.
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge{
	int u,v,weight;
};

struct setnode{

	int parent;
	int rank;
};

Edge get_edge(int u,int v, int weight){

	Edge edge = {u,v, weight};
	return edge;
}

bool compare( Edge u , Edge v){
	return u.weight < v.weight;
}

void print(vector<Edge> graph){

	for (auto x : graph){

		cout << x.u << "---"<< x.v  << "  " << x.weight << "\n";
	}
}


int find (vector<setnode> set,int v){

	if(set[v].parent != v){
		set[v].parent = find(set,set[v].parent);
	}

	return set[v].parent;
}

void Union(vector<setnode>&set, int u, int v){

	int xroot = find(set,u);
	int yroot = find(set,v);

	if(set[xroot].rank < set[yroot].rank){
		set[yroot].parent = xroot;
	}else if(set[xroot].rank > set[yroot].rank){
		set[xroot].parent = yroot;
	}else{

		set[xroot].parent = yroot;
		set[yroot].rank++;
	}
}

void min_spaning_tree(vector<Edge> graph, int no_of_vertices){

	sort(graph.begin(),graph.end(),compare); // sort edges

	vector<setnode> set(no_of_vertices);

	for(int v = 0 ; v < no_of_vertices; v++){
		set[v].parent = v;
		set[v].rank = 0;
	}

	vector <Edge> min_span_tree;

	for(int i = 0 ; i< graph.size(); i++){

		int x = find(set,graph[i].u);
		int y = find(set,graph[i].v);

		if(x!=y){  // not cycle;

			Union(set,graph[i].u,graph[i].v);
		}
		else{ // cycle , then continue no need to add the edge in the min spannig tree
			continue;
		}

		if(min_span_tree.size() <= no_of_vertices -1){
			min_span_tree.push_back(graph[i]);
		}

		if(min_span_tree.size() == no_of_vertices -1){
			break;
		}
	}

	cout << "Min spanning tree is :\n";

	print(min_span_tree);
}

int main(){

	// graph are stored as array of edge;
	// and vertices number stared from 0 .. n
	
	int no_of_vertices = 9;
	vector<Edge> graph;

	graph.push_back(get_edge(0,1,4));
	graph.push_back(get_edge(0,7,8));
	graph.push_back(get_edge(1,7,11));
	graph.push_back(get_edge(1,2,8));
	graph.push_back(get_edge(7,6,1));
	graph.push_back(get_edge(7,8,7));
	graph.push_back(get_edge(2,8,2));
	graph.push_back(get_edge(8,6,6));
	graph.push_back(get_edge(2,3,7));
	graph.push_back(get_edge(2,5,4));
	graph.push_back(get_edge(6,5,2));
	graph.push_back(get_edge(3,5,14));
	graph.push_back(get_edge(3,4,9));
	graph.push_back(get_edge(5,4,10));

	//sort(graph.begin(),graph.end(),compare);

	print(graph);

	min_spaning_tree(graph,no_of_vertices);

}
