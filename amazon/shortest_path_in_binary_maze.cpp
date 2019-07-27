/* 
 * Shortest path in a Binary Maze
Given a MxN matrix where each element can either be 0 or 1. We need to find the shortest path between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1.

Expected time complexity is O(MN).

For example –

Input:
mat[ROW][COL]  = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
                  {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                  {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                  {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
Source = {0, 0};
Destination = {3, 4};

Output:
Shortest Path is 11
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


struct point{

	int x; int y;
};

struct qnode{
	point pt;
	int dist;
};


bool isvalid(int row , int col, int num_rows, int num_cols){

	return ((row >= 0 && row < num_rows) && (col >= 0 && col < num_cols));
}

int minpath(vector<vector<int>>mat, point src, point dest){

	int num_rows = mat.size();
       	int num_cols = mat[0].size();

	vector<int> dirx = {1,0,0,-1};
	vector<int> diry = {0,-1,1,0};

	vector<vector<bool>> visited (num_rows , vector<bool>(num_cols,false));

	queue<qnode> q;
	qnode tmp = {src,0};
	q.push(tmp);

	visited[src.x][src.y] = true;

	while(!q.empty()){

		qnode qn = q.front();
		point pt = qn.pt;

		if(pt.x == dest.x && pt.y == dest.y){
			return qn.dist;
		}

		q.pop();

		for(int i = 0 ; i< 4 ; i++){

			int x = pt.x + dirx[i];
		       	int y = pt.y + diry[i];

			if(isvalid(x,y,num_rows,num_cols) && !visited[x][y] && mat[x][y]!=0){
				qnode tmp = {{x,y},qn.dist+1};
				q.push(tmp);
				visited[x][y] = true;
			}	
		}
	}

	return -1;
}

int main(){

	vector<vector<int>> mat = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
                  {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                  {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                  {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};


	point src = {0,0};
	point dest = {3,4};

	cout << "Shortest path distance is :" << minpath(mat,src,dest);

	return 0;

}

