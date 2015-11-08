/*
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along 
 * the shortest path from the root node down to the nearest 
 * leaf node.
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/
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

struct TreeNode* find_min(struct TreeNode *tr)
{
	struct TreeNode* np;
	np = tr;
	if (np == NULL) return NULL;
	while(np->left != NULL) {
		np = np->left;
	}
	return np;
}

struct TreeNode* find_max(struct TreeNode *tr)
{
	struct TreeNode* np;
	np = tr;
	if (np == NULL) return NULL;
	while(np->right != NULL) {
		np = np->right;
	}
	return np;
}

struct TreeNode* find_value(struct TreeNode *tr, int value) 
{
	if (tr == NULL) return NULL; 

	if (tr->val == value) {
		return tr;
	}
	else if (value < tr->val) {
		return find_value(tr->left, value);
	}
	else {
		return find_value(tr->right, value);
	}
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

int travel_tree(struct TreeNode *root, int prev_lev, int *min) {
	int cur_lev;

	if(!root)
		return 0;
	
	cur_lev = prev_lev + 1;

	if(root->left) {
		travel_tree(root->left, cur_lev, min);
	}
	if(root->right) {
		travel_tree(root->right, cur_lev, min);
	}
	if(!root->left && !root->right) {
		if (cur_lev < *min)
			*min = cur_lev;
	}

	return *min;
}

int minDepth(struct TreeNode* root) {
	int *min = NULL; 

	if (!root)
		return 0;
	min = (int *)calloc(1, sizeof(int));
	*min = INT_MAX;

	travel_tree(root, 0, min);

	return *min;
}
int  main(int argc, char **argv) 
{
	struct TreeNode *tr = NULL;
	int min;
	int i;
	int val[10] = {49, 15, 86, 79, 93, 35, 12, 92, 21, 77};

	tr = NULL;
	
	for(i = 0; i < 10; i++) {
		tr = insert_value(tr, val[i]);
	}	
	
	print_sorted_tree(tr);
	printf("\n");
	
	min = minDepth(tr);
	printf("min depth = %d\n", min);

	return 0;
}
