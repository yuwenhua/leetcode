/*
 * Write a function to find the longest common 
 * prefix string amongst an array of strings.
 * https://leetcode.com/problems/longest-common-prefix/
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

char* longestCommonPrefix(char** strs, int n) {
	int min_len = INT_MAX;
	char *s_str; //shortest str
	int i,j;
	char *res;
	int finished = 0;
	char *tmp;

	
	res = (char *)calloc(1024, sizeof(char));
	if(!strs || n <= 0)
		return res;

	for(i = 0; i < n; i++) {
		if(min_len > strlen(strs[i])) {
			min_len = strlen(strs[i]);
			s_str = strs[i];
		}
	}
	for(i = 0; i < min_len; i++){
		sprintf(res, "%s%c", res, s_str[i]);
		for(j = 0; j < n; j++) {
			tmp = strstr(strs[j], res);
			if(!tmp  ||strlen(tmp) != strlen(strs[j])){
				finished = 1;
				res[i] = '\0';
				break;
			}
		}
		if(finished == 1)
			break;
	}
	return res;
	    
}

int main(int argc, char **argv) 
{
	char **strs;
	char *result;

	strs = (char **)calloc(5, sizeof(char *));
	strs[0] = "yuwh@vnc algorithms";
	strs[1] = "yuwh@vnc leetcode";
	strs[2] = "yuwh@vn algorithms";
	strs[3] = "yuwh@vnc alfdsagorithms";
	strs[4] = "yuwh@vncfda algorithms";

	result = longestCommonPrefix(strs, 5);

	printf("longest common perfix: %s\n", result);

	return 0;
}



