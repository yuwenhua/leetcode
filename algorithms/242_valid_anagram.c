/**Given two strings s and t, write a function to determine if t is an
 * anagram of s.
 *
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 *
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *
 * https://leetcode.com/problems/valid-anagram/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

bool isAnagram(char* s, char* t) {
	int len_s, len_t;
	int i;
	int table[26] = {0}; //hash table;

	len_s = strlen(s);
	len_t = strlen(t);
	if(len_s != len_t) 
		return false;

	for(i = 0; i < len_s; i++) {
		table[s[i]-'a']++;
	}
	for(i = 0; i < len_t; i++) {
		table[t[i]-'a']--;
	}
	for(i = 0; i < 26; i++) {
		if(table[i] > 0)
			return false;
	}
	return true;
}
	    

int main(int argc, char **argv) 
{
	char *s = "iiihello";
	char *t = "lleeeeho";
	bool anagram = false;

	anagram = isAnagram(s,t);
	printf("is %s and %s anagram? %s\n", s, t, anagram?"yes":"no");
	return 0;
}


