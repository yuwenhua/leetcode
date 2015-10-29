/*
 *Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321

 * click to show spoilers.

 * Have you thought about this?
 * Here are some good questions to ask before coding. 
 * Bonus points for you if you have already thought through this!

 * If the integer's last digit is 0, what should the output be? ie, 
 * cases such as 10, 100.

 * Did you notice that the reversed integer might overflow? Assume the input is a 
 * 32-bit integer, then the reverse of 1000000003 overflows. How should you handle 
 * such cases?

 * For the purpose of this problem, assume that your function returns 0
 * when the reversed integer overflows.
 * https://leetcode.com/problems/reverse-integer/
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>


int reverse(int x) {
	char s[16], rs[16];
	int rx;
	int len = 0;
	int negative = 0;
	int i, j = 0;

	memset(s, 0, 16);
	memset(rs, 0, 16);
	sprintf(s, "%d",x);

	len = strlen(s);
	for(i = len -1; i >= 0; i-- ) {
		if(s[i] == '-'){
			negative = 1;
		}
		else {
			rs[j++] = s[i];
		}
	}
	if((strcmp(rs, "2147483647") > 0) && (strlen(rs) == 10))
		return 0;
	

	if(negative) {
		memset(s, 0, 16);
		sprintf(s, "-%s", rs);
		rx = atoi(s);
	}
	else {
		rx = atoi(rs);
	}

	return rx;
}

int main(int argc, char **argv)
{
	int r_val, i;
	int val[15];


	for(i = 0; i < 5; i ++) {
		val[i] = random();
	}
	for(i = 5; i < 10; i ++) {
		val[i] = 0 - random();
	}
	val[10] = 123;
	val[11] = -1230000;
	val[12] = INT_MAX;
	val[13] = INT_MIN;
	val[14] = 0;
	for(i = 0; i < 15; i++) {
		r_val = reverse(val[i]);
		printf("%d reverse: %d\n", val[i], r_val);
	}

	return 0;
}


