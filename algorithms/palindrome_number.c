/*
 * Determine whether an integer is a palindrome. Do this without extra space.
 *
 * click to show spoilers.
 *
 * Some hints:
 * Could negative integers be palindromes? (ie, -1)
 *
 * If you are thinking of converting the integer to string, note the restriction 
 * of using extra space.
 *
 * You could also try reversing an integer. However, if you have solved the 
 * problem  "Reverse Integer", you know that the reversed integer might 
 * overflow. How would you handle such case?
 *
 * There is a more generic way of solving this problem.
 *
 * https://leetcode.com/problems/palindrome-number/
 *
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

bool isPalindrome(int x) {
	int tmp,y;

	if(x < 0)
		return false;
	if(x < 10)
		return true;
	tmp = x;
	y = 0;
	while(tmp) {
		y = (y<<3) + (y<<1); //y *= 10;
		y += tmp%10;
		tmp /= 10;
	}

	return x==y;
}


int main (int argc, char **argv)
{	
	bool result = false;
	int x = 12344321;

	result = isPalindrome(x);

	printf("%d is palindrome?%d\n", x, result);

	return 0;
}

