/* Given an array of integers and an integer k, find out whether 
 * there are two distinct indices i and j in the array such that 
 * nums[i] = nums[j] and the difference between i and j is at most k.
 *
 * https://leetcode.com/problems/contains-duplicate-ii/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
	int i, j;
	int m, n;
	int *new_array;

	new_array = (int *)calloc(numsSize, sizeof(int));

	for(i = 0; i < numsSize; i++){
		memset(new_array, -1, numsSize*sizeof(int));
		m = 0;
		new_array[m++] = i;
		for(j = i+1; j < numsSize; j++){
			if(nums[j] == nums[i]) {
				new_array[m++] = j;

			}
		}
		for(n = 1; new_array[n] != -1; n++){
			if(new_array[n] - new_array[n-1] <= k){
				return true;
			}
		}
	}

	return false;
}

int main(int argc, char **argv) 
{
	int nums[] = {1,2,1};
	int result = false;
	int k = 0;

	result = containsNearbyDuplicate(nums, 3, k);

	printf("result = %d\n", result);
	return 0;
}
