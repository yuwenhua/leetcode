/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a
 * given number of rows like this: (you may want to display 
 * this pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this 
 * conversion given a number of rows:
 *
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 * https://leetcode.com/problems/zigzag-conversion/
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


char* convert(char* s, int numRows) {
	char *result = NULL;
	int i, j, cnt = 0;
	char **str;
	int len;

	if(!s )
		return NULL;

	len = strlen(s);
	str = (char **)malloc(numRows * sizeof(char*));
	memset(str, numRows*sizeof(char*), 0);

	result = (char *)malloc(sizeof(char) * (len+1));
	memset(result, len+1, 0);

	if(numRows <= 1||numRows >= len) {
		strcpy(result, s);
		return result;
	}

	for(i = 0; i < numRows; i++) {
		str[i] = (char *)malloc(sizeof(char) * len);
		memset(str[i], len, 0);
	}
	
	for(i = 0; i < len;i++) {
		for(j = 0; j < numRows; j++) {
			str[j][i] = 0;
		}
	}

	for(i = 0; i < len; i++) {
		for(j = 0; j < numRows; j++) {
			if((i%(numRows-1) == 0) ||
					((j+i)%(numRows-1) == 0)) {
				if(s[cnt]){
					str[j][i] = s[cnt];
					cnt++;
				}
			}
		}
	}

	for(i = 0, cnt = 0; i < numRows; i++){
		for(j = 0; j < len; j++) {
			if(str[i][j]) {
				result[cnt++] = str[i][j];
			}
		}
	}
	for(i = 0; i < numRows; i++){
		free(str[i]);
	}
	free(str);
	result[len] = '\0';
	return result;
}
int main(int argc, char **argv) 
{
	//char *zig = "Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.";
	//char *zig = "0123456789abcdef";
	char *zig = "abcdefghijklmnoqprstuvwxyzrbcdefghijklmnoqprstuvwxyzabcdefghijklmnoqprstuvwxyzabcdefghijklmnoqprstuvwxyzabcdefghijklmnoqprstuvwxyz";
	char *zag ;
	int i;

	for(i = 0; i < 50; i++) {
		printf("numRows = %d\n",i); 
		zag = convert(zig, i);
		if(zag) {
			printf("%d: zag = %s\n", i, zag);
			free(zag);
		}
	}
	return 0;
}


