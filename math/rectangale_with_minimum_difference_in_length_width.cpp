/*Author : Sukanto Mondal*/

/*Rectangle with minimum possible difference between the length and the width
Given an integer area, the task is to find the length and breadth of a rectangle with the given area such that the difference between the length and the breadth is minimum possible.

Examples:

    Input: area = 99
    Output: l = 11, b = 9
    All possible rectangles (l, b) are (99, 1), (33, 3) and (11, 9)
    And the one with the minimum |l – b| is (11, 9)

    Input: area = 25
    Output: l = 5, b = 5 */


#include<iostream>
#include<math.h>
using namespace std;
void find_rec(int area){

	int l, b;

	for(int i= sqrt(area); i>=1; i--){
	
		if(area%i == 0){     // i is a factor
			l = area/i;
			b = i;
			break;
		}
	
	}

	cout << "b is " << b << " and l is " << l;
}

int main (){

	find_rec(99);

	return 0;
}
