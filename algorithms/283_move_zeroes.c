/**
 * Given an array nums, write a function to move all 0's to the end of it 
 * while maintaining the relative order of the non-zero elements.
 *
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, 
 * nums should be [1, 3, 12, 0, 0].
 *
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 *
 * https://leetcode.com/problems/move-zeroes/
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void moveZeroes(int* n, int size) {
	int i,j;
	int count = 0;

	for(i = 0, j = 0; i < size && j < size; i++) {
		while(n[j] == 0 && j < size) {
			j++;
			count++;
		}
		if(i < size && j < size){
			n[i] = n[j];
			j++;
		}
	}
	i = size-count;
	while(i<size){
		n[i] = 0;
		i++;
	}
	    
}
int  main(int argc, char **argv) 
{
	//int n[10] = {0, 0, 00, 0, 00, 0, 00, 00, 00, 00};
	//int n[] = {49, 0, 86, 0, 93, 0, 12, 92, 21, 77};
	int n[] = {0,0,0,0,0,0,0,0,1,0};
	int i;
	
	for(i = 0; i < 10; i++)
		printf("%d ", n[i]);
	printf("\n");

	moveZeroes(n, 10);
	printf("after zero move to tail:\n");
	for(i = 0; i < 10; i++)
		printf("%d ", n[i]);
	printf("\n");

	return 0;
}

