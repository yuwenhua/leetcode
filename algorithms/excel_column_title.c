#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* convertToTitle(int n) {
	char *result;
	int rest = n, power;
	int i = 0;
	int num[20];
	char tmp;

	result = malloc(20); //ignore nomem;
	memset(result, 0, 20);
	memset(num, 0, 20*sizeof(int));

	for(i = 6; i >= 0; i--) {
		power = pow(26, i);
		num[6-i] = rest / power;
		rest = rest % power;
	}
	for(i = 6; i > 0; i--) {
		if((num[i] == 0) && (num[i-1] > 0)) {
			num[i-1] -= 1;
			num[i] = 26;
		}
	}
	for(i = 0; i < 7; i++)  {
		//printf("%d ", num[i]);
		if(num[i] > 0) {
			tmp = num[i] - 1 + 'A';
			strcat(result, &tmp);
		}
	}

	return result;
}

int main(int argc, char **argv) 
{
	int i;
	///int rnd = 0;
	char *result;

	for(i = 1; i < 26*29*26; i++) {
		//rnd = random();
		result = convertToTitle(i);
		printf("%03d-->%s\n", i, result);
		//printf("%d --> %s\n", rnd, result);
		//if(i % 20 == 0) printf("\n");
	}
	free(result);
	printf("\n");
	return 0;
}
