/*
 * Given an integer array nums, find the sum of the elements between 
 * indices i and j (i ≤ j), inclusive.
 *
 * Example:
 * Given nums = [-2, 0, 3, -5, 2, -1]
 *
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * Note:
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 *
 * https://leetcode.com/problems/range-sum-query-immutable/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

struct NumArray {
	int size;
	int *sum;
};

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
	struct NumArray *array;
	int i;

	array = (struct NumArray*)calloc(1, sizeof(struct NumArray));
	array->sum = (int *) calloc(numsSize+1, sizeof(int));
	array->size = numsSize;
	array->sum[0] = 0; 
	for(i = 0; i < numsSize; i++){
		array->sum[i+1] = nums[i] + array->sum[i];
	}
	return array;
}

int sumRange(struct NumArray* numArray, int i, int j) 
{
	int sum = 0;
	
	if(!numArray)
		return 0;
	sum = numArray->sum[j+1] - numArray->sum[i];
	return sum;


}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
	free(numArray->sum);
	free(numArray);
}

// Your Data object will be instantiated and called as such:
// struct NumArray* vwa = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);

int main(int argc, char **argv)
{
	int nums[] = {-8261,2300,-1429,6274,9650,-3267,1414,-8102,6251,-5979,-5291,-4616,-4703};
	int sum = 0;
	
	struct NumArray* numArray = NumArrayCreate(nums, 13);
	
	sum = sumRange(numArray, 0, 1);
	printf("sum = %d\n", sum);
	sum = sumRange(numArray, 0,9);
	printf("sum = %d\n", sum);
	sumRange(numArray, 0,8);
	sumRange(numArray, 4,5);
	sumRange(numArray, 9,11);
	sumRange(numArray, 2,11);
	sumRange(numArray, 0,12);
	sumRange(numArray, 9,12);
	sumRange(numArray, 2,5);
	sumRange(numArray, 0,9);
	sumRange(numArray, 5,9);
	sumRange(numArray, 0,1);
	sumRange(numArray, 12,12);
	sumRange(numArray, 6,7);
	sumRange(numArray, 5,8);
	sumRange(numArray, 1,1);
	sumRange(numArray, 6,7);
	sumRange(numArray, 10,11);
	sumRange(numArray, 11,12);
	sumRange(numArray, 7,8);
	sumRange(numArray, 4,11);
	sumRange(numArray, 8,9);
	sumRange(numArray, 4,11);
	sumRange(numArray, 2,9);
	sumRange(numArray, 2,6);
	sumRange(numArray, 11,12);
	sumRange(numArray, 5,8);
	sumRange(numArray, 11,11);
	sumRange(numArray, 1,9);
	sumRange(numArray, 12,12);
	sumRange(numArray, 10,10);
	sumRange(numArray, 4,7);
	sumRange(numArray, 12,12);
	sumRange(numArray, 8,10);
	sumRange(numArray, 7,9);
	sumRange(numArray, 4,7);
	sumRange(numArray, 0,7);
	sumRange(numArray, 8,9);
	sumRange(numArray, 10,12);
	sumRange(numArray, 0,9);
	sumRange(numArray, 10,12);
	sumRange(numArray, 7,12);
	sumRange(numArray, 9,9);
	sumRange(numArray, 0,12);
	sumRange(numArray, 1,3);
	sumRange(numArray, 8,8);
	sumRange(numArray, 7,10);

	NumArrayFree(numArray);

	return 0;
}


