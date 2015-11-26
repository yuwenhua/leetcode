/**
 * Given a sorted linked list, delete all duplicates such that each 
 * element appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 *
 *https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

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

void list_add_tail(struct ListNode **head, int val) 
{
	struct ListNode *node, *p;

	
	if(!(*head)) {
		*head = (struct ListNode*)calloc(1, sizeof(struct ListNode));
		(*head)->next = NULL;
		(*head)->val = val;
		return ;
	}
	p = *head;
	while(p->next)
		p = p->next;
	node = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	node->val = val;
	node->next = NULL;
	p->next = node;
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
	int val_new;
	int *val_old = NULL;
	struct ListNode *p, *q;

	if(!head) 
		return NULL;
	p = head;
	while(q) {
		val_new = q->val;
		if(!val_old) {
			val_old = (int *)malloc(sizeof(int));
			*val_old = val_new;
			p->next = q;
			p=q;
		}
		else if(*val_old != val_new) {
			*val_old = val_new;
			p->next = q;
			p=q;
		}
		q = q->next;
	}
	return head; 
}
int main (int argc, char **argv)
{
	
	int i;
	int val[] = {1,3,5,7,9,11,11,13,13,15,15,17,17,19,19};
	struct ListNode *l1 = NULL;
	struct ListNode *new = NULL;

	for(i = 0; i < 15; i++) {
		list_add_tail(&l1, val[i]);
	}
	
	print_list(l1);
	new = deleteDuplicates(l1);
	printf("new: \n");
	print_list(new);

	return 0;
}
