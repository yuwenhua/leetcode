/**
 * Given two binary trees, write a function to check if they are equal or not.
 *
 * Two binary trees are considered equal if they are structurally identical 
 * and the nodes have the same value.
 *
 * https://leetcode.com/problems/same-tree/
 */



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct ListNode {
	int val;
	struct ListNode *next;
};
struct TreeLevel {
	int level;
	struct ListNode *node;
};

struct TravelTreeResult {
	int limit;
	struct TreeLevel *tree;
};

bool is_leaf(struct TreeNode* np)
{
	if (np->left == NULL && np->right == NULL)
		return true;
	return false;
}

void print_sorted_tree(struct TreeNode *tr)
{
	if (tr == NULL) return;
	//printf("%d \n", tr->val);
	if(tr->left) {
		printf("%d<--%d ", tr->left->val, tr->val);
	}
	if(tr->right) {
		printf("%d-->%d ", tr->val, tr->right->val);
	}
	print_sorted_tree(tr->left);
	print_sorted_tree(tr->right);
}

void insert_TreeNode_to_nonempty_tree(struct TreeNode *tr, struct TreeNode* np)
{
	/* insert the TreeNode */
	if(np->val <= tr->val) {
		if (tr->left == NULL) {
			/* then tr->left is the proper place */
			tr->left = np;
			return;
		}
		else {
			insert_TreeNode_to_nonempty_tree(tr->left, np);
		}
	}
	else if(np->val > tr->val) {
		if (tr->right == NULL) {
			tr->right = np;
			return;
		}
		else {
			insert_TreeNode_to_nonempty_tree(tr->right, np);
		}
	}
}

struct TreeNode* insert_value(struct TreeNode *tr, int value) {
	struct TreeNode* np;
	/* prepare the TreeNode */
	np = (struct TreeNode*) malloc(sizeof(struct TreeNode));
	np->val = value;
	np->left  = NULL;
	np->right  = NULL;

	if (tr == NULL) tr = np;
	else {
		insert_TreeNode_to_nonempty_tree(tr, np);
	}
	return tr;
}


bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	
	if(!p && !q)
		return true;
	if(!p || !q)
		return false;
	if(p && q) {
		if(p->val == q->val) {
			return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
		}
		else 
			return false;
	}
	else 
		return false;
}

int  main(int argc, char **argv) 
{
	struct TreeNode *tr1 = NULL, *tr2 = NULL;
	int i;
	int val_1[] = {31,42,63,74,85,68,79,18,38,120};
	int val_2[] = {31,42,63,74,85,68,79,18,38,120};
	bool same;

	for(i = 0; i < 10; i++) {
		tr1 = insert_value(tr1, val_1[i]);
	}	
	for(i = 0; i < 10; i++) {
		tr2 = insert_value(tr2, val_2[i]);
	}	
	
	print_sorted_tree(tr1);
	printf("\n");
	print_sorted_tree(tr2);
	printf("\n");
	same = isSameTree(tr1, tr2);
	printf("is tr1 and tr2 the same? %s\n", same?"yes":"no");
	return 0;
}


