/**
 * Reverse a singly linked list.
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could 
 * you implement both?
 *
 * https://leetcode.com/problems/reverse-linked-list/
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
struct ListNode *list_add_head(struct ListNode **head, int val) 
{
	struct ListNode *node;
	
	if(!(*head)) {
		*head = (struct ListNode*)calloc(1, sizeof(struct ListNode));
		(*head)->next = NULL;
		(*head)->val = val;
		return *head;
	}
	node = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	node->val = val;
	node->next = *head;
	*head = node;
	return node;
}
// recursively
void reverse_list(struct ListNode *head, struct ListNode **new) {
	struct ListNode *p;
	
	if(head) {
		p = head->next;
		head->next = *new;
		*new = head;
		head = p;
		reverse_list(head, new);
	}

}
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode *new = NULL;

	reverse_list(head, &new);
	return new;
}
// iteratively 
#if 0
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode *new = NULL;
	int val;

	while(head) {
		val = head->val;
		list_add_head(&new,val);
		head = head->next;
	}
	return new;
}
#endif
int main (int argc, char **argv)
{
	
	int i;
	int val[] = {1,3,5,7,9,11,11,13,15,17,19,23};
	struct ListNode *l1 = NULL;
	struct ListNode *new = NULL;

	for(i = 0; i < 12; i++) {
		list_add_tail(&l1, val[i]);
	}
	
	print_list(l1);
	new = reverseList(l1);
	printf("new: \n");
	print_list(new);

	return 0;
}

