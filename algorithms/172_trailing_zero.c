/*
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 * Note: Your solution should be in logarithmic time complexity.
 *
 * https://leetcode.com/problems/factorial-trailing-zeroes/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>


int trailingZeroes(int n) {
	int result = 0;
	//int tmp = 0;

	while(n >= 5){
		n /= 5;
		result += n;
	}
	return result; 
}

int main(int argc, char **argv)
{
	int n = 1808548329;
	//int n = 125;
	int result = 0;

	result = trailingZeroes(n);

	printf("%d!'s trailing zero = %d\n", n, result);

	return 0;
}

