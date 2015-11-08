/*
 * Write a program to find the node at which the intersection of 
 * two singly linked lists begins.
 *
 * For example, the following two linked lists:
 *
 * A:          a1 → a2
 *                    ↘
 *                        c1 → c2 →3 
 *                    ↗            
 * B:     b1 → b2 → b3
 * begin to intersect at node c1.
 * Notes:
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function 
 * returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 *
 * https://leetcode.com/problems/intersection-of-two-linked-lists/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

/**
 * Definition for singly-linked list.
 */
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

struct ListNode *getIntersectionNode(struct ListNode *head_a,
		struct ListNode *head_b) 
{
	int len_a = 0, len_b = 0;
	struct ListNode *p, *pa, *pb;
	int i;

	if(!head_a || !head_b)
		return NULL;

	p = head_a;
	while(p) {
		len_a++;
		p = p->next;
	}
	p = head_b;
	while(p) {
		len_b++;
		p = p->next;
	}
	
	if(len_a >= len_b) {
		pa = head_a;
		i = 0;
		pb = head_b;
		while(i < len_a-len_b) {	
			pa = pa->next;
			i++;
		}
	}
	else {
		pb = head_b;
		pa = head_a;
		i = 0;
		while(i < len_b-len_a) {	
			pb = pb->next;
			i++;
		}
	}
	
	while( pa && pb && pa->val != pb->val ) {
		pa = pa->next;
		pb = pb->next;
	}
	return pa;
    
}
int main (int argc, char **argv)
{
	
	int i;
	int val_a[] = {1,3,5,7,9,11,13,15,17,19,21};
	int val_b[] = {2};
	//int val[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	struct ListNode *head_a = NULL;
	struct ListNode *head_b = NULL;
	struct ListNode *head_i = NULL;
	
	head_a = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	head_a->val = 100;
	head_a->next = NULL;

	for(i = 0; i < 11; i++) {
		list_add_tail(head_a, val_a[i]);
	}
	head_b = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	head_b->val = 200;
	head_b->next = NULL;

	for(i = 0; i < 1; i++) {
		list_add_tail(head_b, val_b[i]);
	}
	
	print_list(head_a);
	print_list(head_b);
	head_i = getIntersectionNode(head_a, head_b);
	print_list(head_i);
	return 0;
}




