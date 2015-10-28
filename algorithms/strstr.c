/*
 * Implement strStr().
 * Returns the index of the first occurrence of needle in haystack, 
 * or -1 if needle is not part of haystack.
 *
 * https://leetcode.com/problems/implement-strstr/
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int strStr(char* haystack, char* needle) {
	int i, j;
	int len, len_needle;
	int result = -1;

	if(!haystack || !needle)
		return -1;

	len = strlen(haystack);
	len_needle = strlen(needle);
	for(i = 0; i < len; i++) {
		if(j == len_needle) {
			result = i;
			break;
		}
		for(j = 0; j < len_needle; j++) {
			if(haystack[i+j]) {
				if(haystack[i+j] != needle[j])
					break; //j loop
			}
		}
	}
	return result;

}

int main(int argc, char **argv) 
{
	//int i;
	int result;
	char *haystack = "https://leetcode.com/problems/implement-strstr/";
	char *needle = "problems";

	result = strStr(haystack, needle);

	printf("result = %d\n", result);

	return 0;
}

