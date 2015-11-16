/*
 * Given a non-negative number represented as an array of digits, plus one to the number.
 * The digits are stored such that the most significant digit is at the head of the list.
 *
 * https://leetcode.com/problems/plus-one/
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int *res;
	int i;
	int carry = 1;

	if(digitsSize <= 0)
		return NULL;


	res = (int *)calloc(digitsSize+1, sizeof(int));
	*returnSize = digitsSize + 1;
	
	for(i = digitsSize; i > 0; i--) {
		res[i] = carry + digits[i-1];
		if(res[i] == 10) {
			res[i] = 0;
			carry = 1;
		}
		else {
			carry = 0;
		}
	}
	res[0] += carry;
	if(res[0] == 0){
		res = &res[1];
		*returnSize -= 1;
	}

	return res;
}

int main(int argc, char **argv)
{
	int returnSize;
	int digits[9] = {9,9,9,9,9,9,9,9,9};
	int *res;
	int i;

	//digits = (int *)calloc(12,sizeof(int));
	res = plusOne(digits, 9, &returnSize);

	for(i = 0; i < returnSize; i++) {
		printf("%d", res[i]);
	}
	printf("\n");
	return 0;
}



