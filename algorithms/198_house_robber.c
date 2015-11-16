/*
 * You are a professional robber planning to rob houses along a street. Each house has a 
 * certain amount of money stashed, the only constraint stopping you from robbing each of 
 * them is that adjacent houses have security system connected and it will automatically 
 * contact the police if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of each house, 
 * determine the maximum amount of money you can rob tonight without alerting the police.
 *
 * Credits:
 * Special thanks to @ifanchu for adding this problem and creating all test cases. 
 * Also thanks to @ts for adding additional test cases.
 *
 *	https://leetcode.com/problems/house-robber/
 */
#define MAX(a,b) a>b?a:b

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

int rob(int* n, int nS) {
	int dp[nS+1];
	int i;
	
	dp[0] = 0;
	dp[1] = n[0];

	for(i = 1; i<= nS; i++)	{
		dp[i+1] = MAX(dp[i], dp[i-1] + n[i]);
	}

	return dp[nS];
}

int main(int argc, char **argv)
{
	int money[13] = {192,38,283,48,75,89,75,58,19,5,66,29,18};
	int result;

	result = rob(money, 13);
	printf("max money will be %d\n", result);

	return 0;
}

