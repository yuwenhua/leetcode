/*
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 *
 * Credits:
 * Special thanks to @mithmatt for adding this problem and creating all test cases.
 *
 * https://leetcode.com/problems/remove-linked-list-elements/
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>


struct ListNode {
	int val;
	struct ListNode *next;
};

void print_list(struct ListNode *head)
{
	struct ListNode *p;

	p = head;
	while(p && p->next){
		printf("%d->", p->val);
		p = p->next;
	}
	if(p)
		printf("%d\n", p->val);
}

struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode *pp, *p, *pn; //prev, cur, next;

	if(!head)
		return NULL;

	pp = head;
	while(pp && pp->next && pp->next->next) {
		p = pp->next;
		pn = p->next;
		if(p->val == val) {
			pp->next = pn;
			p->next = NULL;
			p->val = 0;
			free(p);
			p = NULL;
		}
		else {
			pp = pp->next;
		}
	}
	p = head;
	//printf("removing head:\n");
	if(head && head->next) {
		if(head->val == val) {
			p = head;
			head = head->next;
			free(p);
		}
	}
	//printf("removing tail:\n");
	p = head;
	while(p && p->next) {
		if (p->next->val == val) {
			free(p->next);
			p->next = NULL;
		}
		p = p->next;
	}
	if(head && head->val == val)
		head = NULL;
			
	return head;
}
void list_add_tail(struct ListNode *head, int val) 
{
	struct ListNode *node, *p;
	
	if(!head) {
		return;
	}
	p = head;
	while(p->next)
		p = p->next;
	node = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	node->val = val;
	node->next = NULL;
	p->next = node;
}

int main (int argc, char **argv)
{
	
	int i;
	int val[] = {1,1,1,1,1,5,4,6,1,32,1,1,1,453,2,1,1,1,1,1};
	//int val[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	struct ListNode *head = NULL;
	
	head = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	head->val = 1;
	head->next = NULL;

	for(i = 0; i < 20; i++) {
		list_add_tail(head, val[i]);
	}
	
	print_list(head);
	head = removeElements(head, 1);
	printf("removed:\n");
	print_list(head);

	return 0;
}




