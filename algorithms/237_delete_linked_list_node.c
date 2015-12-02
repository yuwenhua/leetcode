/**
 * Write a function to delete a node (except the tail) in a singly linked 
 * list, given only access to that node.
 *
 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third 
 * node with value 3, the linked list should become 1 -> 2 -> 4 after calling
 * your function.
 *
 * https://leetcode.com/problems/delete-node-in-a-linked-list/
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
	int val_new, val_old;
	struct ListNode *p, *q;

	if(!head) 
		return NULL;
	p = head;
	val_old = head->val;
	q = head->next;

	while(q) {
		val_new = q->val;
		if(val_old != val_new) {
			val_old = val_new;
			p->next = q;
			p=q;
		}

		q = q->next;
	}
	p->next = NULL;
	return head; 
}

void deleteNode(struct ListNode* node) {
	struct ListNode *nextnode = node->next;
	
	node->val = nextnode->val;
	node->next = nextnode->next;
}
int main (int argc, char **argv)
{
	
	int i;
	int val[] = {1,3,5,7,9,10,11,12,13,14,15,16,17,18,19};
	struct ListNode *l1 = NULL;

	for(i = 0; i < 15; i++) {
		list_add_tail(&l1, val[i]);
	}
	
	print_list(l1);
	deleteNode(l1->next->next->next);
	printf("new: \n");
	print_list(l1);

	return 0;
}
