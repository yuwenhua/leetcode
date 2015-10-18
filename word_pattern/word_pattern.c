#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wordPattern(char* pattern, char* str) 
{
	char *token[1024], *saveptr;
	int p_len;
	int i, j;
	char *tmp_str;

	if(! pattern || ! str) {
		return 0;
	}
	p_len = strlen(pattern);
	tmp_str = malloc(strlen(str)); //ignore enomem
	strcpy(tmp_str, str);

	j = 0;
	while((token[j] = strtok_r(tmp_str, " ", &saveptr)) != NULL) {
		j++;
		tmp_str = NULL;
	}
	if (j != p_len) 
		goto not_match;

	for(i = 0; i < p_len; i++) {
		for(j = i+1; j < p_len; j++) {
			if((pattern[i] == pattern[j]) !=
					(strcmp(token[i], token[j]) == 0 )){
				goto not_match;
			}
		}
	}
	free(tmp_str);
	return 1;
not_match:
	free(tmp_str);
	return 0;
}
int main(int argc, char **argv) 
{
	char *pattern[6] = {
		"abab",
		"abcda",
		"aaaaaba",
		"abbacdad",
		"abbacaad",
		"abcaabad"
	};
	char *string[6] = {
		"dog cat dog cat",
		"dog cat fish pig dog",
		"dog dog dog dog dog cat dog",
		"dog cat cat dog fish pig dog pig",
		"dog cat cat dog fish dog dog pig",
		"dog cat fish dog dog cat dog pig"
	};
	char tmp[100];
	int i, j;
	int result = 0;

	for(i = 0; i < 6; i ++) {
		for(j = 0; j < 6; j++) {
			memset(tmp, 0, sizeof(tmp));
			strcpy(tmp, string[j]);
			result = wordPattern(pattern[i], tmp);
			printf("%d ", result);
		}
		printf("\n");
			
	}
	return 0;
}
