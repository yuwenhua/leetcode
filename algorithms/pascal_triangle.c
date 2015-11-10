/*
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 * For example, given k = 3,
 * Return [1,3,3,1].
 *
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 * https://leetcode.com/problems/pascals-triangle-ii/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* getRow(int rowIdx, int* retS)
{
	int i = 0, j = 0;
	*retS = rowIdx+1;
	int nR = rowIdx + 1, idx = 0;
	int **ret = (int**)malloc(sizeof(int*)* 2); /* ping-pong */

	for(i = 0; i<2; i++)
	{
		ret[i] = (int*)malloc(sizeof(int)* nR);
		memset(ret[i], 0, sizeof(int)*nR);    
	}

	for(i = 0; i<nR; i++, idx^=1) {
		for(j=0; j<i+1; j++) {
			if(j == 0 || j == i)  
				ret[idx][j] = 1; 
			else
				ret[idx][j] = ret[idx^1][j-1] + ret[idx^1][j];
		}
	}

	return ret[idx^1];

}

int main(int argc, char **argv)
{
	int *row = NULL;;
	int size = 0;
	int i;

	row = getRow(31, &size);
	for(i = 0; i < size ; i++){
		printf("%d ", row[i]);
	}
	printf("\n");

	return 0;
}
