/*
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 *
 * Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
 *
 * Rectangle Area
 * Assume that the total area is never beyond the maximum possible value of int.
 *
 * Credits:
 * Special thanks to @mithmatt for adding this problem, creating the above image and all test cases.
 *
 * https://leetcode.com/problems/rectangle-area/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	struct rect {
		int x0,x1;
		int y0,y1;
	};
	int x, y;
	int area = 0;
	int overlap = -1; 
	struct rect left, right;
	struct rect up, down;
	
	if(A <= E) {
		left.x0 = A; left.x1 = C; right.x0 = E; right.x1 = G; 
	}
	else {
		left.x0 = E; left.x1 = G; right.x0 = A; right.x1 = C; 
	}
	
	if( B <= F)  {
		up.y0 = F; up.y1 = H; down.y0 = B; down.y1 = D;
	}
	else {
		up.y0 = B; up.y1 = D; down.y0 = F; down.y1 = H;
	}

	if(left.x1 <= right.x0) 
		overlap = 0; // no cross
	else {
		if(left.x1 >= right .x1) 
			x = right.x1 - right.x0;

		else if(left.x1 < right.x1) 
			x = left.x1 - right.x0;
		
		if(down.y1 <= up.y0)
			overlap =  0;
		else {

			if(down.y1 >= up.y1)
				y = up.y1 - up.y0;
			else if(up.y0 < down.y1) {
				y = down.y1 - up.y0;
			}
		}
	}
	if (overlap != 0) 
		overlap = x * y;
	if(overlap < 0)
		overlap = 0;

	area = (C-A) * (D-B) + (G-E) * (H-F) - overlap;
	printf("overlap = %d, area = %d\n", overlap, area);
	
	return area;
	
}

int main(int argc, char **argv) 
{
	int area = 0;

	area = computeArea(-2,-2,2,2,-2,-2,2,2);
	//area = computeArea(-3,0,3,4,0,-1,9,2);
	//area = computeArea(0,0,0,0, -1,-1,1,1);
	printf("area = %d\n", area);

	return 0;
}
