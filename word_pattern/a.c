#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *str1, *str2, *token, *subtoken;
	char *saveptr1, *saveptr2;
	int j;

	char argv1[] =  "a/bbb///cc;xxx:yyy:";
	char *argv2 = ";:";
	char *argv3 = "/";


	for (j = 1, str1 = argv1; ; j++, str1 = NULL) {
		token = strtok_r(str1, argv2, &saveptr1);
		if (token == NULL)
			break;
		printf("%d: %s\n", j, token);

		for (str2 = token; ; str2 = NULL) {
			subtoken = strtok_r(str2, argv3,  &saveptr2);
			if (subtoken == NULL)
				break;
			printf(" --> %s\n", subtoken);
		}
	}

	exit(EXIT_SUCCESS);
}

