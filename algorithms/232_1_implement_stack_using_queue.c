/**
 * Implement the following operations of a stack using queues.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 * Notes:
 * You must use only standard operations of a queue -- which means only push 
 * to back,  peek/pop from front, size, and is empty operations are valid.
 * Depending on your language, queue may not be supported natively. You may 
 * simulate a queue by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top 
 * operations will be called on an empty stack).
 *
 * https://leetcode.com/problems/implement-stack-using-queues/
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

typedef struct {
	int cursize;
	int maxsize;
	struct ListNode *node;
} Stack;

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

void list_add_head(struct ListNode **head, int val) {
	struct ListNode *node;
	
	node = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	node->val = val;
	node->next = *head;
	*head = node;
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

/* Create a stack */
void stackCreate(Stack *stack, int maxSize) {
	//stack = (Queue *)calloc(1, sizeof(Queue));
	memset(stack, 0, sizeof(Stack));
	stack->maxsize = maxSize;
	stack->cursize = 0;
	stack->node = NULL;
}

/* Push element x onto stack */
void stackPush(Stack *stack, int element) {
	list_add_head(&(stack->node), element);
	stack->cursize++;
}

/* Removes the element on top of the stack */
void stackPop(Stack *stack) {
	struct ListNode *head;

	head = stack->node;
	if(head) {
		stack->node = stack->node->next;
		stack->cursize--;
		free(head);
	}
}

/* Get the top element */
int stackTop(Stack *stack) {
	if(stack)
		return stack->node->val;
	return INT_MIN;
}

/* Return whether the stack is empty */
/* Return whether the stack is empty */
bool stackEmpty(Stack *stack) {
	if(!stack)
		return true;
	else 
		return (stack->cursize == 0);
}

/* Destroy the stack */
void stackDestroy(Stack *stack) {
	struct ListNode *head;
	head = stack->node;
	while(head) {
		stack->node = stack->node->next;
		free(head);
		head = stack->node;
	}
}

int main (int argc, char **argv)
{
	int i;
	int val[] = {2,3,6,8,10,12,14,16,18,20,21,22,23,24,25};
	Stack s ;

	stackCreate(&s, 1024);
	for(i = 0; i < 15; i++) {
		stackPush(&s, val[i]);
		print_list(s.node);
	}

	for(i = 0; i < 15; i++) {
		stackPop(&s);
		print_list(s.node);
	}
	stackDestroy(&s);

	return 0;
}
