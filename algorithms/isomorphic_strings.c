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
	char dic_s[128] = {0};
	char dic_t[128] = {0};
	int i, len;
	char cs, ct;

	if(!s || !t)
		return true;

	len = strlen(s);
	for(i = 0; i < len; i++) {
		cs = s[i];
		ct = t[i];
		if(dic_s[(int)cs] == 0 && dic_t[(int)ct] == 0) {
			dic_s[(int)cs] = ct;
			dic_t[(int)ct] = cs;
		}
		else if(dic_s[(int)cs] != ct)
			return false;
		else if(dic_t[(int)ct] != cs)
			return false;
	}


	return true;
}

int main(int argc, char **argv) 
{
	char *s = "aba";
	char *t = "baa";
	bool result;

	result = isIsomorphic(s, t);

	printf("%s and %s is isomorphic? %d\n", s, t, result);

	return 0;
}
