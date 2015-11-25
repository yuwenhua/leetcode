/**
 * Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process: Starting with 
 * any positive integer, replace the number by the sum of the squares of its 
 * digits, and repeat the process until the number equals 1 (where it will stay),
 * or it loops endlessly in a cycle which does not include 1. Those numbers 
 * for which this process ends in 1 are happy numbers.
 *
 * Example: 19 is a happy number
 *
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * Credits:
 * Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.
 *
 * https://leetcode.com/problems/happy-number/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

bool isHappy(int n) {
	int nums[32] = {0};
	int i = 0, j = 0;
	int result = 0;

	if(n <= 0)
		return false;
	while(n) {
		nums[i] = n % 10;
		n /= 10;
		i++;
	}
	for(j = 0; j < i; j++) {
		//printf("%d ", nums[j]);
 		result += nums[j] * nums[j];
	}
	//printf("\n");
	if(result >= 10)
		return (isHappy(result));
	else 
		return result == 1;
}

int main(int argc, char **argv) 
{
	int val[] = {1111221,3,5,7,9,11,13,15,17,19,21,22,23,24,25};
	int i;
	bool happy;

	for(i = 0; i < 15; i++) {
		happy = isHappy(val[i]);
		printf("Is %d a happy number? %s\n", val[i], happy?"yes":"no");
	}
	return 0;
}

