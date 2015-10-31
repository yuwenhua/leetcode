/*
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 * https://leetcode.com/problems/palindrome-linked-list/
 *
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

bool isPalindrome(struct ListNode* head) {
	struct ListNode *pp = NULL, *p = NULL, *pn = NULL;
	struct ListNode *s1, *s2; //step 1, step 2;

	if(!head)
		return false;
	if(head->next == NULL)
		return true;

	s1 = head;	s2 = head;
	while(s1->next && s2->next && s2->next->next) {
		s1 = s1->next;
		s2 = s2->next;
		s2 = s2->next;
	}
	p = s1->next;
	s1->next = NULL;
	while(p->next) {
		pn = p->next;
		p->next = pp;
		pp = p;
		p = pn;
	}
	p->next = pp;
#if 0 
	s1 = head;
	while(s1->next){
		printf("%d->", s1->val);
		s1 = s1->next;
	}
	printf("%d\n", s1->val);

	s2 = p;
	while(s2->next){
		printf("%d->", s2->val);
		s2 = s2->next;
	}
	printf("%d\n", s2->val);
#endif

	while(head->next && p->next) {
		if(p->val != head->val) {
			return false;
		}
		p = p->next;
		head = head->next;
	}	
	if(head->val != p->val) 
		return false;
	return true;
	    
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
	int val[] = {1,3,1};
	struct ListNode *head = NULL, *p;
	bool result = 0;
	
	head = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	head->val = 1;
	head->next = NULL;

	for(i = 0; i < 3; i++) {
		list_add_tail(head, val[i]);
	}
	
	p = head;
	while(head->next){
		printf("%d->", head->val);
		head = head->next;
	}
	printf("%d\n", head->val);

	result = isPalindrome(p);

	printf("is palindrome? %d\n", result);

	return 0;
}




