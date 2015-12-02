/**
 * Given a non-negative integer num, repeatedly add all its digits until the 
 * result has only one digit.
 *
 * For example:
 *
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has
 * only one digit, return it.
 *
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 *
 * Hint:
 *
 * A naive implementation of the above process is trivial. Could you come up 
 * with other methods?
 * What are all the possible results?
 * How do they occur, periodically or randomly?
 * You may find this Wikipedia article useful.
 *
 * https://leetcode.com/problems/add-digits/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

int addDigits(int n) {

	return (n-1) % 9 + 1;
#if 0
	int sum = 0;

	if(n < 10)
		return n;

	while(n >= 10) {
		sum += n % 10;
		n /= 10;
	}
	sum += n;
	return addDigits(sum);
#endif
	    
}

int main(int argc, char **argv) 
{
	int n = random();
	int result;
	int i;

	for(i = 0; i < 20; i++) {
		n = random();
		result = addDigits(n);
		printf("%d add digits = %d\n", n, result);
	}

	return 0;
}

