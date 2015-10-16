#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLastWord(char* s) {
        int s_len = 0;
    int i = 0;
    int result = 0, tmp_result = 0;

    if(! s) {
        printf("input null\n");
        return 0;
    }
    s_len = strlen(s);

    for(i = 0; i < s_len; i++) {
        if(s[i] != ' ') {
            tmp_result++;
        }
        else {
            if(tmp_result != 0)
                result = tmp_result;
            tmp_result = 0;
        }
    }
    if(result == 0 || s[s_len-1] != ' ')
        result = tmp_result;
    return result;

}

int main(int argc, char **argv) 
{
	char *s[5] = {
		"    ",
		"a    ",
		"Welcome join ithe conference      ",
		"Today is a nice day ",
		"Today is a nice day"
	};
	int i = 0;
	int length = 0;

	for(i = 0; i < 5; i ++) {
		length = lengthOfLastWord(s[i]);
		printf("length = %d\n", length);
	}

	return 0;
}
