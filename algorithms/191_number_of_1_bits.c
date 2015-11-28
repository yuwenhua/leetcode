/**
 * Write a function that takes an unsigned integer and returns the number 
 * of ’1' bits it has (also known as the Hamming weight).
 *
 * For example, the 32-bit integer ’11' has binary representation
 * 00000000000000000000000000001011, so the function should return 3.
 *
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
 *
 * https://leetcode.com/problems/number-of-1-bits/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

typedef  unsigned int uint32_t;

int hammingWeight(uint32_t n) {
	int i = 0; 
	int weight = 0;
	for(i = 0; i < 32; i++) {
		weight += n & 0x01;
		n >>= 1;
	}
	return weight;
	    
}

int main(int argc, char **argv) 
{
	int i;
	int n;
	int weight;

	for(i = 0; i < 10; i++) {
		n = random() & 0xFFFFFFFF;
		weight = hammingWeight(n);
		printf("hamming weight of %d is %d\n", n, weight);
	}
	return 0;
}

