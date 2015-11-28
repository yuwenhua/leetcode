/**
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 *https://leetcode.com/problems/roman-to-integer/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

int getVal(char c){
	switch(c){
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
	}
	return -1;
}
int romanToInt(char* s) {
	int len = strlen(s);
	int sum=0;
	int i;

	for(i = 0; i < len; i++){
		if(i < len-1 && (getVal(s[i]) < getVal(s[i+1])) ){
			sum += getVal(s[i+1]) - getVal(s[i]);
			i++;
		}
		else {
			sum += getVal(s[i]);
		}
	}
	return sum;
}

int main(int argc, char **argv) {
	char  *roman = "III";
	int integer;

	integer = romanToInt(roman);

	printf("%s = %d\n", roman, integer);

	return 0;
}

