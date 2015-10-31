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
	int i_a = 0, i_b = 0, i_c = 0;
	int i = 0;
	char *first_one = NULL;

	if(!a || !b)
		return result;

	if(strlen(a) > 32 ||(strlen(b) > 32))
		return result;


	while(a[i]) {
		if(a[i] == '1') {
			i_a |= 1;
		}
		i++;
		if(a[i])
			i_a <<=  1;
	}
	i = 0;
	while(b[i]) {
		if(b[i] == '1') {
			i_b |= 1;
		}
		i++;
		if(b[i])
			i_b <<= 1;
	}
	i_c = i_a + i_b;
	
	//over flow?
	if(i_c < i_a || i_c < i_b)  
		return NULL;

	printf("%d + %d = %d\n", i_a, i_b, i_c);
	
	result = (char *)calloc(32, sizeof(char));
	for(i = 0; i < 32; i ++) {
		if(i_c & ( 1 << i)) 
			result[31-i] = '1';
		else 
			result[31-i] = '0';
	}
	printf("%s + %s = %s\n", a, b, result);
	first_one = strchr(result, '1');
	
	if(!first_one) {
		sprintf(result, "%d", 0);
		return result;
	}
	return first_one;

}

int main(int argc, char **argv) 
{
	char *a = "11";
	char *b = "10";
	char *result = NULL;

	result = addBinary(a, b);

	if(result) {
		printf("a + b = %s\n", result);
	}

	return 0;
}

