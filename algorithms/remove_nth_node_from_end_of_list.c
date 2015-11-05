/*
 * Given a linked list, remove the nth node from the end of 
 * list and return its head.
 * For example,
 *
 * Given linked list: 1->2->3->4->5, and n = 2.
 *
 * After removing the second node from the end, 
 * the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode *p, *pp;
	int cnt = 0;
	int i;

	if(!head)
		return NULL;
	p = head;
	while(p) {
		cnt++;
		p = p->next;
	}
	printf("cnt = %d\n", cnt);
	if(n > cnt)
		return NULL;
	p = head;
	pp = NULL;
	for(i = 0; i < (cnt-n); i++) {
		pp = p;
		p = p->next;
	}

	if(!pp) {
		head = head->next;
	}
	else {
		if(p) 
			pp->next = p->next;
	}
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
	int val[] = {1,2,14,17,18,5,4,6,14,32,41,1432,1,453,2,4321,51,6541,41,146};
	//int val[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	struct ListNode *head = NULL;
	
	head = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	head->val = 1;
	head->next = NULL;

	for(i = 0; i < 20; i++) {
		list_add_tail(head, val[i]);
	}
	
	print_list(head);
	head = removeNthFromEnd(head, 21);
	printf("removed:\n");
	print_list(head);

	return 0;
}
