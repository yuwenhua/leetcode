/**Implement the following operations of a queue using stacks.
 *
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.
 * Notes:
 * You must use only standard operations of a stack -- which means only push 
 * to top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. You may 
 * simulate a stack by using a list or deque (double-ended queue), as long as 
 * you use only standard operations of a stack.
 * You may assume that all operations are valid (for example, no pop or peek 
 * operations will be called on an empty queue).
 *
 * https://leetcode.com/problems/implement-queue-using-stacks/
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
} Queue;


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

/* Create a queue */
void queueCreate(Queue *queue, int maxSize) {
	//queue = (Queue *)calloc(1, sizeof(Queue));
	memset(queue, 0, sizeof(Queue));
	queue->maxsize = maxSize;
	queue->cursize = 0;
	queue->node = NULL;
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element) {
	list_add_tail(&(queue->node), element);
	queue->cursize += 1;
}

/* Removes the element from front of queue */
void queuePop(Queue *queue) {
	struct ListNode *head;
	head = queue->node;
	if(head) {
		queue->node = queue->node->next;
		queue->cursize -= 1;
		free(head);
	}
}

/* Get the front element */
int queuePeek(Queue *queue) {
	if(queue)
		return queue->node->val;
	return INT_MIN;
}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue) {
	if(!queue)
		return true;
	else 
		return (queue->cursize == 0);
}

/* Destroy the queue */
void queueDestroy(Queue *queue) {
	struct ListNode *head;
	head = queue->node;
	while(head) {
		queue->node = queue->node->next;
		free(head);
		head = queue->node;
	}
	//free(queue);
}

int main (int argc, char **argv)
{
	int i;
	int val[] = {2,3,6,8,10,12,14,16,18,20,21,22,23,24,25};
	int value;
	Queue q ;

	queueCreate(&q, 1024);
	for(i = 0; i < 15; i++) {
		queuePush(&q, val[i]);
		print_list(q.node);
	}

	for(i = 0; i < 15; i++) {
		value = queuePeek(&q);
		printf("val = %d\n", value);
		queuePop(&q);
		print_list(q.node);
	}
	queueDestroy(&q);

	return 0;
}
