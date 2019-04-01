/* Author : Sukanto Mondal */

/*Flood fill Algorithm
 *
 * Input:
       screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1},
                      };
    x = 4, y = 4, newColor = 3
The values in the given 2D screen indicate colors of the pixels.
x and y are coordinates of the brush, newColor is the color that
should replace the previous color on screen[x][y] and all surrounding
pixels with same color.

Output:
Screen should be changed to following.
       screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 3, 3, 3, 3, 0, 1, 0},
                      {1, 1, 1, 3, 3, 0, 1, 0},
                      {1, 1, 1, 3, 3, 3, 3, 0},
                      {1, 1, 1, 1, 1, 3, 1, 1},
                      {1, 1, 1, 1, 1, 3, 3, 1},
                      };
		      */

#include<iostream>
#include<vector>
using namespace std;

void flood_fill(vector<vector<int>> &scr, int x, int y,int preC, int currC){

	if(x< 0 || x >= scr[0].size() || y<0 || y>= scr.size())
		return;

	if(scr[x][y]!=preC)
		return;

	scr[x][y]=currC;

	flood_fill(scr,x+1,y,preC,currC);
	flood_fill(scr,x-1,y,preC,currC);
	flood_fill(scr,x,y+1,preC,currC);
	flood_fill(scr,x,y-1,preC,currC);
}


void print_screen(vector<vector<int>> &scr){

	for(int i = 0 ; i < scr.size(); i++){
		for(int j=0; j < scr[i].size(); j++){
			cout<< scr[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(){

	vector<vector<int>> scr = {{1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 0, 0},
                        {1, 0, 0, 1, 1, 0, 1, 1},
                        {1, 2, 2, 2, 2, 0, 1, 0},
                        {1, 1, 1, 2, 2, 0, 1, 0},
                        {1, 1, 1, 2, 2, 2, 2, 0},
                        {1, 1, 1, 1, 1, 2, 1, 1},
                        {1, 1, 1, 1, 1, 2, 2, 1},
                        };

	int x = 4; int y = 4; int currC = 3;
	cout << "The screen before color\n\n";
	print_screen(scr);
	
	flood_fill(scr,x,y,scr[x][y],currC);

	cout << "The screen after color \n\n";
	print_screen(scr);

	return 0;
}
