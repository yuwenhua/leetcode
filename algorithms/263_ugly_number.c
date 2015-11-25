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
    if(n <= 0)
        return false;

    while((n % 2) == 0){
        n >>= 1;
    }
    while((n % 3) == 0){
        n  /= 3;
    }
    while((n % 5) == 0){
        n /= 5;
    }

    return (n == 1);
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

