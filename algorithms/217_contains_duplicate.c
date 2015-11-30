/**
 * Given an array of integers, find if the array contains any duplicates. 
 * Your function should return true if any value appears at least twice in 
 * the array, and it should return false if every element is distinct.
 *
 * https://leetcode.com/problems/contains-duplicate/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

struct list_node {
	int val;
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
	
	idx %= table->size;
	p = table->bucket[idx];
	while(p){
		if(p->val == val) {
			return false;
		}
		p = p->next;
	}

	p = (struct list_node *)calloc(sizeof(struct list_node), 1);
	p->next = table->bucket[idx];
	p->val = val;
	table->bucket[idx] = p;

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

bool containsDuplicate(int* nums, int numsSize) {
	int i;
	int not_found;
	struct hash_table table;

	init_table(&table, numsSize);


	for(i = 0; i < numsSize; i++) {
		not_found = add_value(&table, nums[i]);
		if(not_found == false) {
			release_table(&table);
			return true;
		}
	}
	release_table(&table);
	return false;
}

int main(int argc, char **argv) 
{
	//int array[] = {1,2,3,6,7,7,7,7,7,7,1,2,7,7,7,7,7,7,7,8};
	int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	bool duplicate = false;

	duplicate = containsDuplicate(array, 20);
	printf("duplicate? %s\n", duplicate?"yes":"no");
	return 0;
}


