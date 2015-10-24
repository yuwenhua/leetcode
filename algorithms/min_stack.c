/*
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 *
 * https://leetcode.com/problems/min-stack/
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

typedef struct {
	int *top;
	int	*bot;
	int maxSize;
	    
} MinStack;
inline int check_valid(MinStack *stack) {
	if(!stack|| !stack->top)
		return 0;
	if(stack->bot - stack->top >= stack->maxSize)
		return 0;
	return 1;
}
void minStackCreate(MinStack *stack, int maxSize) {

	if(!stack) 
		return;

	stack->top = (int*) calloc(maxSize * sizeof(int), 0);
	stack->bot = stack->top + maxSize -1;
	stack->top = stack->bot;
	stack->maxSize = maxSize;
}

void minStackPush(MinStack *stack, int element) {
	
	if(!check_valid(stack)) 
		return;

	stack->top--;
	*stack->top = element;
}

void minStackPop(MinStack *stack) {
	if(!check_valid(stack)) 
		return;
	if(stack->bot > stack->top) {
		stack->top++;
	}
}

int minStackTop(MinStack *stack) {
	if(!check_valid(stack)) 
		return -1;
	return *stack->top;
	    
}

int minStackGetMin(MinStack *stack) {
	int min;
	int *cur;
	
	if(!check_valid(stack)) 
		return -1;

	cur = stack->top;
	min = *cur;

	while(cur < stack->bot) {
		if(min > *cur)
			min = *cur;
		cur++;
	}
	return min;
}

void minStackDestroy(MinStack *stack) {
	int *start;
	
	if(!check_valid(stack)) 
		return;
	start = stack->bot - stack->maxSize + 1;
	free(start);
	free(stack);
}
int main(int argc, char **argv) 
{
	int i;
	MinStack	*stack;
	int maxSize = 8192;
	int top, min;


	minStackPush(stack, -3);
	min = minStackGetMin(stack);
	printf("min = %d\n", min);

#if 1	
	stack = (MinStack *)malloc(sizeof(MinStack));
	minStackCreate(stack, maxSize);

	minStackPush(stack, -8);
	min = minStackGetMin(stack);
	printf("push 20:\n");
	for(i = 0;i < 20; i++) {
		minStackPush(stack, i+4);
		min = minStackGetMin(stack);
		top = minStackTop(stack);
		printf("%d %d %d\n", i, min, top);
	}
	printf("pop 20:\n");
	for(i = 0;i < 20; i ++) {
		min = minStackGetMin(stack);
		top = minStackTop(stack);
		minStackPop(stack);
		printf("%d %d %d\n", i, min, top);
	}
	minStackDestroy(stack);
#endif
	return 0;
}
