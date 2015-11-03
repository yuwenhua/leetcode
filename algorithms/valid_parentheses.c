/*
 * Given a string containing just the characters 
 * '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 *
 * The brackets must close in the correct order, 
 * "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 * 
 * https://leetcode.com/problems/valid-parentheses/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

bool isValid(char* s) {
	int len;
	int i,j,k;
	char *str;

	if(!s)
		return false;
	len = strlen(s);
	if(len % 2 == 1 || len == 0)
		return false;
	str = (char *)calloc(len, sizeof(char));
	strcpy(str, s);

	for(k = 0; k < len; k++) {
		for(i = 0; i < len; i++) {
			if(str[i] == '(') {
				for(j = i+1; j < len; j++) {
					if(str[j] == 0)
						j++;
					else 
						break;
				}
				if(str[j] == ')') {
					str[i] = 0;
					str[j] = 0;
				}
			}

			if(str[i] == '[') {
				for(j = i+1; j < len; j++) {
					if(str[j] == 0)
						j++;
					else 
						break;
				}
				if(str[j] == ']') {
					str[i] = 0;
					str[j] = 0;
				}
			}

			if(str[i] == '{') {
				for(j = i+1; j < len; j++) {
					if(str[j] == 0)
						j++;
					else 
						break;
				}
				if(str[j] == '}') {
					str[i] = 0;
					str[j] = 0;
				}
			}
		}
	}
	for(i = 0; i < len; i++) {
		if(str[i] != 0)
			return false;
	}

	return true;

	    
}

int main(int argc, char **argv)
{
	char *str = "(([[]})){}";
	bool result;

	result = isValid(str);

	printf("Is %s  valid? %d\n", str, result);
	return 0;
}

