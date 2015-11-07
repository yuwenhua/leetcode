/*
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * For example, given input 43261596 (represented in binary as 
 * 00000010100101000001111010011100), return 964176192
 * (represented in binary as 00111001011110000010100101000000).
 *
 * Follow up:
 * If this function is called many times, how would you optimize it?
 *
 * https://leetcode.com/problems/reverse-bits/ 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

typedef  unsigned int uint32_t;
//typedef uint32_t uint32;


#if 1 
uint32_t reverseBits(uint32_t n) {
	int i = 0;
	uint32_t reversed_i = 0;

	for(i = 0; i < 31; i++) {
	    reversed_i |= (n & (1<< i))?1:0;
		reversed_i <<= 1;
	}
	reversed_i |= (n & (1<< i))?1:0;
	
	return reversed_i < 0? -reversed_i:reversed_i;// & 0x7FFFFFFF;
	//return reversed_i & 0x7FFFFFFF;
	
}
#else
uint32_t reverseBits(uint32_t n) { 
	if(n==0) 
		return 0; 
	int i; 
	int a=0,m=0; 
	for(i=0;i<32;i++) { 
		a=n&1; 
		if(a==0) { 
			n>>=1; 
			m<<=1; 
		} 
		else { 
			n>>=1; 
			m<<=1; 
			m=m+1; 
		} 
	} 
	return m; 
}
#endif
int main(int argc, char **argv)
{
	int reversed_int;
	//int n = 2147483648;
	//int n = 1;
	int n = 43261596;

	reversed_int = reverseBits(n);

	printf("reverse %d = %d\n", n, reversed_int);
	return 0;
}
