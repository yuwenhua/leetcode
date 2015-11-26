/**
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct 
 * ways can you climb to the top?
 *
 * https://leetcode.com/problems/climbing-stairs/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

int climbStairs(int n) {
	int ways[2] = {0};
	int i;
	if(n == 0) return 1;
	if(n == 1) return 1;
	if(n >=2) {
		ways[0] = 1;
		ways[1] = 1;
	}
	for(i = 0; i < n; i++) {
		ways[i & 0x01] = ways[0] + ways[1];
	}
	return ways[i&0x01] ;
}

int main(int argc, char **argv) 
{
	int val[] = {1111221,1,2,3,4,5,6,9,717,19,21,22,23,24,25};
	int i;
	int ways;

	for(i = 0; i < 15; i++) {
		ways = climbStairs(val[i]);
		printf("%d : %d \n", val[i], ways);
	}
	return 0;
}


