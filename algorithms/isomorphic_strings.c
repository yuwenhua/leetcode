/*
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be 
 * replaced to get t.
 *
 * All occurrences of a character must be replaced with another character 
 * while preserving the order of characters. No two characters may map 
 * to the same character but a character may map to itself.
 *
 * For example,
 * Given "egg", "add", return true.
 *
 * Given "foo", "bar", return false.
 *
 * Given "paper", "title", return true.
 *
 * Note:
 * You may assume both s and t have the same length.
 * https://leetcode.com/problems/isomorphic-strings/
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

bool isIsomorphic(char* s, char* t) {
	int len;
	int i,j;

	if(!s || !t)
		return true;

	len = strlen(s);
	for(i = 0; i < len; i++) {
		for(j = i+1; j < len;j++){
			if(s[i] == s[j]) {
				if(t[i] != t[j])
					return false;
			}
			else if(t[i] == t[j])
				return false;
		}
	}

	return true;
}

int main(int argc, char **argv) 
{
	char *s = "abbefg";
	char *t = "eggabb";
	bool result;

	result = isIsomorphic(s, t);

	printf("%s and %s is isomorphic? %d\n", s, t, result);

	return 0;
}
