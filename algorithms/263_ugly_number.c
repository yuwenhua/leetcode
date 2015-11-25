/**
 * Write a program to check whether a given number is an ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
 * For example, 6, 8 are ugly while 14 is not ugly since it includes another 
 * prime factor 7.
 *
 * Note that 1 is typically treated as an ugly number.
 *
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating 
 * all test cases.
 *
 * https://leetcode.com/problems/ugly-number/
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

bool isUgly(int n) {
	int i, j = 0;
	int factor[64] = {0};
	int sqr = 0;

	if(n <= 0)
		return false;

	while( n %2 == 0) {
		factor[j++] = 2;
		n /= 2;
	}
	sqr = sqrt(n);
	for(i = 3; i <= sqr; i += 2) {  
		if( n % i == 0) {
			n /= i;
			factor[j++] = i;
			i -= 2;
		}  
	}
	if(n != 1) 
		factor[j++] = n;	
	for(i = 0; i < j; i++) {
		//printf(" %d * ", factor[i]);
		if(factor[i] != 2 && factor[i] != 3 &&
				factor[i] != 5)
			return false;
	}
	return true;

}
int main(int argc, char **argv) 
{
	int val[] = {1111221,32,50,30,92,113,134,152,174,196,218,228,238,242,258};
	int i;
	bool ugly;

	for(i = 0; i < 15; i++) {
		ugly = isUgly(val[i]);
		printf("Is %d a ugly number? %s\n", val[i], ugly?"yes":"no");
	}
	return 0;
}

