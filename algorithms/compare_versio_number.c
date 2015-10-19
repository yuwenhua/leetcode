#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int compareVersion(char* version1, char* version2) 
{
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
		"1.1"
	};
	int result = 0;

	for(i = 0; i < 8; i++) {
		for(j = i+1; j < 8; j++) {
			result = compareVersion(string[i],string[j]);
			printf("%s --> %s: %d\n", string[i], string[j], result);
		}
	}
	return 0;
}
