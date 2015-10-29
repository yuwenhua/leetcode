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

int *get_next(char *p)
{
	int i = 0, j = -1;
	int len;
	int *next;


	len = strlen(p);
	next = (int *)calloc(sizeof(int), len);
	next[0] = -1;
	
	while(i < len-1)  {
		if(j == -1 || p[i] == p[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
	return next;
}

int strStr(char* s, char* p) 
{
	int i = 0, j = 0;
	int p_len, s_len;
	int *next;


	if(!s || !p)
		return -1;
	s_len = strlen(s);
	p_len = strlen(p);

	if(p_len == 0)
		return 0;

	next = get_next(p);
	for(i = 0; i < p_len; i++) {
		printf("%d, ", next[i]);
	}
	while(i < s_len && j < p_len) {
		if(j == -1 || s[i] == p[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if( j == p_len)
		return i-j;
	else
		return -1;
}

int main(int argc, char **argv)
{
	int result;
	
	char *haystack = "BBC ABCDAB ABCDABCDABDE";
	char *needle = "ABCDABD";

	result = strStr(haystack, needle);

	printf("result = %d\n", result);

	return 0;
}
