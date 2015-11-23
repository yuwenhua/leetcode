/*
 * Given an array and a value, remove all instances of that value in place and
 * return the new length.
 * The order of elements can be changed. It doesn't matter what you leave 
 * beyond the new length.
 *
 * https://leetcode.com/problems/remove-element/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

int removeElement(int* nums, int size, int val) {
	int i,j;

	if(!nums || size == 0)
		return 0;

	for(i = 0, j = 0; i < size; i++) {
		if(nums[i] != val) {
			nums[j] = nums[i];
			j++;
		}
	}

	if(j == 0){
		return 0;
	}

	return j;
}

int main(int argc, char **argv) {
	int nums[] = {1,2,3,3,3,4,4,4,5,5,5,6,7,8,2,6,6,65,5,54,4,4,3,3,3,2,2,2};
	int result = 0;
	int i;

	result = removeElement(nums, 28, 2);
	for(i = 0; i < result; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");

	return 0;
}


