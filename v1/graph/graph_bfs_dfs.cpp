// Make a graph and then do traversal 

#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

void add_edge(vector<list<int>>&graph_adj,int u, int v){
	graph_adj[u].push_back(v);
}

void bfs_search(vector<list<int>>&graph_adj, int s){

	int v = graph_adj.size(); // graph size
	
	vector<bool> visited(v,false);
	queue<int> q;

	q.push(s);
	visited[s]= true;

	while(!q.empty()){
		s = q.front();
		q.pop();
		cout << s << " ";

		for(int x : graph_adj[s]){     // push all of the adjacent node if not visited;
			if(!visited[x]){
				q.push(x);
				visited[x]=true;
			}
		}
	}

	cout << "\n";
}

void dfs_search(vector<list<int>>&graph_adj, int s){

	int v = graph_adj.size(); // graph size

	vector<bool> visited(v,false);
	stack<int> st;
	
	st.push(s);
	visited[s] = true;

	cout << s << " ";

	while(!st.empty()){

		s = st.top();

		bool is_not_visited_found = false;
		for ( int x : graph_adj[s]){      // push only one of the adjacent node in the stack

			if(!visited[x]){
				st.push(x);
				cout << x << " ";
				visited[x] = true;
				is_not_visited_found = true;
				break;
			}
		}

		if(!is_not_visited_found)  // if no valid (not visited) adjacent node found 
			st.pop();
	}

	cout << "\n";


}

int main(){

	int v = 9;  // size of the graph
	vector<list<int>> graph_adj(v);
	add_edge(graph_adj,0,1);
	add_edge(graph_adj,0,2);
	add_edge(graph_adj,1,3);
	add_edge(graph_adj,1,4);
	add_edge(graph_adj,2,5);
	add_edge(graph_adj,3,6);
	add_edge(graph_adj,4,6);
	add_edge(graph_adj,4,7);
	add_edge(graph_adj,5,7);
	add_edge(graph_adj,6,8);
	add_edge(graph_adj,7,8);

	cout << "The bfs search is : ";
	bfs_search(graph_adj,0);

	cout << "The dfs search is : ";
	dfs_search(graph_adj,0);

	return 0;
}
