/**
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 * For example:
 * A -> 1
 * B -> 2
 * C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28 
 *
 * https://leetcode.com/problems/excel-sheet-column-number/
 *
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>

int titleToNumber(char* s) {
	int num = 0;
	int len;
	int i;
	
	if(!s)
		return 0;

	len = strlen(s);
	for(i = len-1; i >=0 ; i--) {
		num += (s[len-1-i]-'A'+1) * pow(26,i);
		printf("num = %d\n", num);
	}
	return num;
}

int main(int argc, char **argv) 
{
	char *s = "ABC";
	int num;

	num = titleToNumber(s);
	printf("%s -> %d\n", s, num);
	return 0;
}
