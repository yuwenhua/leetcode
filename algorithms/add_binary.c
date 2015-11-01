/*
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 * https://leetcode.com/problems/add-binary/
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


char* addBinary(char* a, char* b) {
	char *result = NULL;
	int i = 0;
	int len_a, len_b, max;
	int carry = 0;
	char tmp_a, tmp_b;
	int tmp;
	char *first_one;

	if(!a || !b)
		return NULL;

	len_a = strlen(a);
	len_b = strlen(b);
	if(len_a > 1023 || len_b > 1023) 
		return NULL;

	result = (char *)calloc(1024, sizeof(char));
	memset(result, '0', 1024);

	max = len_a > len_b?len_a:len_b;
	
	for(i = 0; i < max; i++) {
		if(i >= len_a)
			tmp_a = '0';
		else 
			tmp_a = a[len_a-1-i];
		if(i >= len_b)
			tmp_b = '0';
		else
			tmp_b = b[len_b-1-i];
		tmp = tmp_a + tmp_b + carry - '0' - '0';

		if(tmp >=2 ) {
			result[1023-i] = '0' + tmp - 2;
			carry = 1;
		}
		else {
			result[1023-i] = '0' + tmp;
			carry = 0;
		}
	}
	if(carry) {
		result[1023-i] = '1';
	}
	first_one = strchr(result, '1');
	if(first_one == NULL) {
		result[0] = '0';
		result[1] = '\0';
	}
	else {
		result = first_one;	
	}
	printf("%s+%s = %s\n", a, b, result);
	return result;
}

int main(int argc, char **argv) 
{
	char *a = "111";
	char *b = "1101";
	char *result = NULL;

	result = addBinary(a, b);

	if(result) {
		printf("a + b = %s\n", result);
	}

	return 0;
}

