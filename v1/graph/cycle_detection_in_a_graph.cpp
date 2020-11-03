/* detect a cycle in a graph */


#include <iostream>
#include <vector>
#include <stack>
#include<list>
using namespace std;

struct node_st{
	bool is_visited;
	int parent;
};

void add_edge(vector<list<int>> &graph_adj, int u , int v){
	graph_adj[u].push_back(v);
}


void detect_cycle(vector<list<int>> &graph_adj, int s){
	int v = graph_adj.size();
	vector<node_st> visited(v,{false,-1});

	bool is_cycle = false;

	stack<int> st;
	st.push(s);
	visited[s] = {true,-1};

	int cycle_node = -1;

	while(!st.empty()){

		s = st.top();

		bool is_pushed = false;

		for(auto x: graph_adj[s]){
			
			if(visited[x].is_visited){
				is_cycle= true;
				cycle_node= s;	
				visited[x]={true,s};

				while(!st.empty())
					st.pop();  // remove all element from stack to stop the algorithm.
				break;
			}
			else if(!is_pushed){
				st.push(x);
				visited[x]={true,s};
				is_pushed= true;
			}
		}

		if(!is_pushed && !st.empty()){
			st.pop();
		}
		
	}

	if(is_cycle){
		cout << "Cycle found\n";

		vector<int> cycle_path;
		int node = cycle_node;
		cycle_path.insert(cycle_path.begin(),node);
		while(visited[node].parent != cycle_node){
			node = visited[node].parent;
			cycle_path.insert(cycle_path.begin(),node);
		}

		for (auto x : cycle_path){
			cout << x << " ";
		}

	}else{
		cout << "No cycle found\n";
	}
}

int main(){

	int v = 6; // size of the graph
	vector<list<int>> graph_adj(v);

	add_edge(graph_adj,0,1);
	add_edge(graph_adj,0,2);
	add_edge(graph_adj,1,3);
	add_edge(graph_adj,4,1);
	add_edge(graph_adj,2,5);
	add_edge(graph_adj,3,4);

	detect_cycle(graph_adj,0);

	return 0;
}
