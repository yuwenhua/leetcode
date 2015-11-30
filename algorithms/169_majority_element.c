/**
 * Given an array of size n, find the majority element. The majority 
 * element is the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element
 * always exist in the array.
 *
 * https://leetcode.com/problems/majority-element/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>



struct list_node {
	int val;
	int count;
	struct list_node *next;
};

struct hash_table {
	int size;
	struct list_node **bucket;
};

bool init_table(struct hash_table *table, int size)
{
	if(!table)
		return false;
	table->bucket = (struct list_node **)calloc(sizeof(struct list_node), size);
	table->size = size;

	return true;
}

bool add_value(struct hash_table *table, int val) {
	int idx = val > 0 ? val : -val;
	struct list_node *p;
	bool found = false;
	
	idx %= table->size;
	p = table->bucket[idx];
	while(p){
		if(p->val == val) {
			p->count++;
			if(p->count > table->size/2) {
				return false;
			}
			found = true;
			break;
		}
		p = p->next;
	}

	if(!found) {
		p = (struct list_node *)calloc(sizeof(struct list_node), 1);
		p->next = table->bucket[idx];
		p->val = val;
		p->count = 1;
		table->bucket[idx] = p;
	}

	return true;
}

int del_value(struct hash_table *table, int val) {
	int idx = val > 0 ? val : -val;
	struct list_node *p, *pp;

	if(!table) 
		return -1;

	idx %= table->size;

	p = table->bucket[idx];
	pp = NULL;
	while(p && p->val != val) {
		pp = p;
		p = p->next;
	}
	if(p && (p->val == val)) {
		if(pp)
			pp->next = p->next;
		else 
			table->bucket[idx] = p->next;
		free(p);
	}

	return 0;
}
int release_table(struct hash_table *table) {
	int i;
	struct list_node *p, *pn;

	if(!table)
		return -1;

	for(i = 0; i < table->size; i++){
		p = table->bucket[i];
		while(p){
			pn = p->next;
			free(p);
			p = pn;
		}
	}
	table->bucket = NULL;
	table->size = 0;

	return 0;
}

int majorityElement(int* nums, int numsSize) {
	int i;
	int not_found;
	struct hash_table table;

	init_table(&table, numsSize);

	if(numsSize < 2)
		return nums[0];

	for(i = 0; i < numsSize; i++) {
		not_found = add_value(&table, nums[i]);
		if(not_found == false) {
			release_table(&table);
			return nums[i];
		}
	}
	release_table(&table);
	return -1; // not found?
}

int main(int argc, char **argv) 
{
	int array[] = {1,2,3,6,7,7,7,7,7,7,1,2,7,7,7,7,7,7,7,8};
	int majority;

	majority = majorityElement(array, 20);
	printf("majority = %d\n", majority);
	return 0;
}

