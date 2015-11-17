/*
 * Given a sorted array, remove the duplicates in place such that each element appear 
 * only once and return the new length.
 * Do not allocate extra space for another array, you must do this in place with 
 * constant memory.
 *
 * For example,
 * Given input array nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements of nums being 1 
 * and 2 respectively. It doesn't matter what you leave beyond the new length.
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

int removeDuplicates(int* n, int size) {
	int i, j;

	if(size <= 1) {
		return size;
	}

	for(i = 1, j = 1; i < size; i++) {
		if(n[i] != n[i-1]) {
			n[j] = n[i];
			j++;
		}
	}
	return j;


}

int main(int argc, char **argv)
{
	int n[] = {1,1,1,2,3,3,3,3,3,3,4,4,4,5};
	int size;
	int i;

	size = removeDuplicates(n, 14);
	
	for(i = 0; i < size; i++)
		printf("%d, ", n[i]);

	printf("\n");

	return 0;
}

