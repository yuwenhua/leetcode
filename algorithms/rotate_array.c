#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void rotate(int* nums, int numsSize, int k) {
	int i;
	int *tmp_nums;

	tmp_nums = malloc(numsSize * sizeof(int));
	
	
	k = k % numsSize;
	if(! nums || numsSize <= 0) {
		return;
	}

	for(i = 0; i < numsSize; i++) {
		tmp_nums[i] = nums[i];
	}

	for(i = 0; i < numsSize; i ++) {
		if(i < k) {
			nums[i] = tmp_nums[i + numsSize - k];
		}
		else {
			nums[i] = tmp_nums[i-k];
		}
	}
	free(tmp_nums);
}

int main(int argc, char **argv) 
{
	int num0[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i, j;

	for(i = 0; i < 20; i++) {
		rotate(num0, 10, i);
		for(j = 0; j < 10; j++) {
			printf("%d ", num0[j]);
			num0[j] = j;
		}
		printf("\n");
	}
	return 0;
}
