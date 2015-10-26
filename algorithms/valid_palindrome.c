/*
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
 * https://leetcode.com/problems/valid-palindrome/
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

bool isPalindrome(char* s) {
	int i,j;
	int len;
	bool all_space = true;

	char *new_s, *reverse_s;
	
	if(!s)
		return false;
	len = strlen(s);

	for(i = 0; i < len; i++) {
		if( s[i] != ' '){
			all_space = false;
		}
	}
	if(all_space)
		return true;

	new_s = (char *)calloc(len+1, sizeof(char));
	reverse_s = (char *)calloc(len+1, sizeof(char));

	for(i = 0, j= 0; i < len; i++){
		if((s[i] >= 'a' && s[i] <= 'z') ||
				(s[i] >= 'A' && s[i] <= 'Z') ||
				(s[i] >= '0' && s[i] <= '9')) {
			new_s[j] = s[i];
			if(new_s[j] >= 'A' && new_s[j] <= 'Z')
				new_s[j] += 32;
			j++;
		}
	}
	new_s[j] = '\0';
	len = strlen(new_s);

	for(i = 0, j = len-1; i < len; i++) {
		reverse_s[j--] = new_s[i];
	}
	reverse_s[len] = '\0';
	
	if(strcmp(new_s, reverse_s) == 0) {
		free(new_s);
		free(reverse_s);
		return true;
	}
	else {
		free(new_s);
		free(reverse_s);
		return false;
	}
}

int main(int argc, char **argv)
{
	//char *s = "Live on evasions? No I save no evil.";
	//char *s = "A man, a plan, a canal: Panama";
	char *s = "1a2";
	int result = 0;

	result = isPalindrome(s);
	printf("%s is  palindrome? %d\n", s, result);

	return 0;
}
