/*
 * Given two sorted integer arrays nums1 and nums2, 
 * merge nums2 into nums1 as one sorted array.
 *
 * Note:
 * You may assume that nums1 has enough space (size that is greater 
 * or equal to m + n) to hold additional elements from nums2. 
 * The number of elements initialized in nums1 and nums2 are m 
 * and n respectively.
 * 
 * https://leetcode.com/problems/merge-sorted-array/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>


void merge(int* nums1, int m, int* nums2, int n) {
	int i,j,k;
	int a,b;
	int new_array[m]; 

	memset(new_array, 0, m*sizeof(int));
	for(i = 0; i < m; i++)
		new_array[i] = nums1[i];
	memset(nums1, 0, (m+n)*sizeof(int));

	i = 0; j = 0; k = 0;

	while(i < m && j < n) {
		a = new_array[i];
		b = nums2[j];
		if(a < b) {
			nums1[k++] = a;
			i++;
		}
		else if(a == b) {
			nums1[k++] = a;
			nums1[k++] = a;
			i++;
			j++;
		}
		else {
			nums1[k++] = b;
			j++;
		}
	}
	while(i < m) {
		nums1[k++] = new_array[i++];
	}
	while(j < n) {
		nums1[k++] = nums2[j++];
	}
}


int main(int argc, char **argv) 
{
	int nums1[32]; 
	int nums2[] = {2,4,22};
	int i;

	memset(nums1, 0, 32*sizeof(int));

	for(i = 0; i < 10; i++)
		nums1[i] = i;

	merge(nums1, 10, nums2, 3);
	for(i = 0; i < 32; i++) {
		while(nums1[i] != 0)
			printf("%d ",nums1[i++]);
	}
	printf("\n");
	return 0;
}
