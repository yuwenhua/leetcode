#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int compareVersion(char* version1, char* version2) 
{
	char *token1[1024], *saveptr1;
	char *token2[1024], *saveptr2;
	char *tmp_str1, *tmp_str2;
	int i;
	int v1_len = 0, v2_len = 0;
	int ver1[1024], ver2[1024];
	int max_len = 0;

	tmp_str1 = malloc(1024); //ignore enomem
	tmp_str2 = malloc(1024); //ignore enomem
	memset(tmp_str1, 0, 1024);
	memset(tmp_str2, 0, 1024);
	memset(ver1, 0, 1024);
	memset(ver2, 0, 1024);
	strcpy(tmp_str1,version1);
	strcpy(tmp_str2,version2);

	v1_len = 0;
	while((token1[v1_len] = strtok_r(tmp_str1, ".", &saveptr1)) != NULL) {
		v1_len++;
		tmp_str1 = NULL;
	}
	v2_len = 0;
	while((token2[v2_len] = strtok_r(tmp_str2, ".", &saveptr2)) != NULL) {
		v2_len++;
		tmp_str2 = NULL;
	}

	for(i = 0; i < v1_len; i++) {
		ver1[i] = atoi(token1[i]);
	}
	for(i = 0; i < v2_len; i++) {
		ver2[i] = atoi(token2[i]);
	}
	free(tmp_str1);
	free(tmp_str2);
	max_len = v1_len > v2_len ? v1_len : v2_len;
	for(i = 0; i < max_len;i++) {

		if(ver1[i] > ver2[i])
			return 1;
		else if(ver1[i] < ver2[i]){
			return -1;
		}
	}

	return 0;
}

int main(int argc, char **argv) 
{
	int i = 0, j = 0;
	char *string[8] = {
		"1.1",
		"1.2.3",
		"0.5",
		"123.45",
		"1.2.3.4",
		"4.2323.5",
		"4.12.5",
		"1.001.3"
	};
	int result = 0;

	for(i = 0; i < 8; i++) {
		for(j = 0; j < 8; j++) {
			result = compareVersion(string[i],string[j]);
			printf("%s --> %s: %d\n", string[i], string[j], result);
			//printf("%2d ", result);
		}
		printf("\n");
	}
	return 0;
}
