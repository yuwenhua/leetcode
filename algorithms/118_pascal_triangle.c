/*
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5, Return
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 *
 * https://leetcode.com/problems/pascals-triangle/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be 
 * malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes, int* returnSize) {
	int **result;
	int i,j;

	*returnSize = numRows;
	*columnSizes = (int *)calloc(*returnSize, sizeof(int *));
	result = (int **)calloc(*returnSize, sizeof(int *));
	
	for(i = 0; i < numRows; i++) {
		result[i] = (int *)calloc(i+1, sizeof(int));
		(*columnSizes)[i] = i+1;
		for(j = 0; j < i+1; j++) {
			if(j == 0 || j == i) {
				result[i][j] = 1;
			}
			else {
				result[i][j] = result[i-1][j-1] + result[i-1][j];
			}
		}
	}

	return result;
}

int main(int argc, char **argv) 
{
	int n = 5;
	int i, j;
	int **result = NULL;
	int *columnSizes = NULL;
	int returnSize;

	result = generate(n, &columnSizes, &returnSize);
	for(i = 0; i < returnSize; i++) {
		for(j = 0; j < columnSizes[i]; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}


