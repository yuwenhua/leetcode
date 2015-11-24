/**
 * Merge two sorted linked lists and return it as a new list. The new 
 * list should be made by splicing together the nodes of the first two lists.
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/
 */

/**
 * Definition for singly-linked list.
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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *head = NULL;
	int val1 , val2, val_new;

	while(l1 || l2) {
		if(l1) 
			val1 = l1->val;
		if(l2) 
			val2 = l2->val;
		if((val1 < val2) && l1) {
			val_new = val1;
			l1 = l1->next;
		}
		else if((val1 >= val2) && l2){
			val_new = val2;
			l2 = l2->next;
		}
		else if(!l1 && l2) {
			val_new = l2->val;
			l2 = l2->next;
		}
		else if(!l2 && l1) {
			val_new = l1->val;
			l1 = l1->next;
		}
		list_add_tail(&head, val_new);
	}

	return head;
	    
}
int main (int argc, char **argv)
{
	
	int i;
	int val_1[] = {1,3,5,7,9,11,13,15,17,19,21,22,23,24,25};
	int val_2[] = {2,3,6,8,10,12,14,16,18,20,21,22,23,24,25};
	//int val[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	struct ListNode *l1 = NULL;
	struct ListNode *l2 = NULL;
	struct ListNode *new = NULL;
	

	for(i = 0; i < 15; i++) {
		list_add_tail(&l1, val_1[i]);
	}
	for(i = 0; i < 15; i++) {
		list_add_tail(&l2, val_2[i]);
	}
	
	print_list(l1);
	print_list(l2);
	new = mergeTwoLists(l1, l2);
	printf("new: \n");
	print_list(new);

	return 0;
}
