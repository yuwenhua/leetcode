/*
 * Given an integer, write a function to determine if it is a power of two.
 *
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and 
 * creating all test cases.
 *
 * https://leetcode.com/problems/power-of-two/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>


bool isPowerOfTwo(int n) {
	int i;
	int	result = 0;

	if(n < 0)
		return false;

	for(i = 0; i < 32; i++) {
		if(((n >> i) & 0x01) == 1){
			result++;
			if(result > 1)
				break;
		}
	}
	printf("n = %d, result = %d\n", n, result);
	if(result == 1)
		return true;
	return false;
	    
}

int main(int argc, char **argv) {
	int x[] = {2,4,8,16,32,64,128,256,512,1024,2048,4096,7};
	int i;
	bool result;

	for(i = 0; i < 13; i++) {
		result = isPowerOfTwo(x[i]);
		printf("%d is power of 2? %d\n", x[i], result);
	}
	return 0;
}

