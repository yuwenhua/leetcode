/*
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 *
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 *
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 * https://leetcode.com/problems/summary-ranges/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
	char **result;
	int i;
	int start, end;

	if(!nums || numsSize == 0) {
		return NULL;
	}

	result = (char **)malloc(numsSize * sizeof(char*)); // ENOMEM? 
	*returnSize = 0;
	start = nums[0];

	if(numsSize == 1) {
		(*returnSize)++;
		result[*returnSize-1] = (char *)calloc(32, sizeof(char));
		sprintf(result[*returnSize-1], "%d", start);
	}
	for(i = 1; i < numsSize; i++)  {
		if((nums[i] != nums[i-1]+1) ) {
			(*returnSize)++;
			result[*returnSize-1] = (char *)calloc(32, sizeof(char));
			end = nums[i-1];
			if(start < end) {
				sprintf(result[*returnSize-1], "%d->%d", start, end);
			}
			else {
				sprintf(result[*returnSize-1], "%d", start);
			}
			if(i <= numsSize -1) {
				start = nums[i];
			}
		}
		if(i == numsSize-1){
			(*returnSize)++;
			result[*returnSize-1] = (char *)calloc(32, sizeof(char));
			result[*returnSize-1] = result[*returnSize-1];
			end = nums[i];
			if(start < end) {
				sprintf(result[*returnSize-1], "%d->%d", start, end);
			}
			else {
				sprintf(result[*returnSize-1], "%d", start);
			}
		}
	}
	
	return result;
    
}
int main(int argc, char **argv) 
{
	int returnSize;
	char **summary;
	int i;
	
	//int nums[] = {-2,-1,1,2,2147483646,2147483647};
	//int nums[] = {1};
	//int nums[] = {1, 2};
	//int nums[] = {1, 5};
	//int nums[] = {1,2,5};
	//int nums[] = {INT_MIN, INT_MIN+1, INT_MIN+3, 0, 1, 2, INT_MAX-3, INT_MAX-2, INT_MAX-1, INT_MAX};
	//int nums[] = {-9, -8,-7, -6, -5, -4, -3};
	//int nums[] = {1,2,3,4,5,6,7,8,9};
	int nums[] = {1,3,5,7,9,11,13,15,17};
	//int nums[] = {1,2,3,4,8,20,21,22,23, 25, 26, 28};
	//int nums[] = {0,1,2,4,5,7};
	

	summary = summaryRanges(nums, sizeof(nums)/sizeof(int), &returnSize);

	printf("size: %d\n", returnSize);
	for(i = 0; i < returnSize; i++) {
		printf("%s, ",summary[i]);
		free(summary[i]);
	}
	printf("\n");
	free(summary);

	return 0;
}
