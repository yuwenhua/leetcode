/*
 * The count-and-say sequence is the sequence of integers beginning
 * as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 *
 * Note: The sequence of integers will be represented as a string.
 *
 * https://leetcode.com/problems/count-and-say/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

char *count_say(char *input, char *output) 
{
	int len;
	int i;
	char c;
	int cnt = 0;
	char tmp[128] = {0};

	len = strlen(input);
	c = input[0];
	cnt = 1;
	for(i = 1; i < len; i++) {
		if(input[i] == input[i-1]) {
			cnt++;
		}
		else {
			memset(tmp, 0, 128);
			sprintf(tmp, "%d%d", cnt, c-'0');
			strcat(output, tmp);
			c = input[i];
			cnt = 1;
		}
	}
	memset(tmp, 0, 128);
	sprintf(tmp, "%d%d", cnt, c - '0');
	strcat(output, tmp);
	return output;
}

char* countAndSay(int n) {
	int i;
	char *str = (char *)calloc(40960, sizeof(char));
	char *ret = (char *)calloc(40960, sizeof(char));

	sprintf(str, "%d", 1);
	for(i = 0; i < n; i++) {
		count_say(str, ret);
		strcpy(str, ret);
		memset(ret, 0, 40960);
	}
	return str;
}

int main (int argc, char **argv)
{
	char *res;
	int n = 9;

	res = countAndSay(n);

	printf("%d:%s\n", n, res);

	return 0;
}

