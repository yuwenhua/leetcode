/**
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path 
 * from the root node down to the farthest leaf node.
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/
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

int travel_tree(struct TreeNode *root, int prev_lev, int *max) {
	int cur_lev;

	if(!root)
		return 0;
	
	cur_lev = prev_lev + 1;

	if(root->left) {
		travel_tree(root->left, cur_lev, max);
	}
	if(root->right) {
		travel_tree(root->right, cur_lev, max);
	}
	if(!root->left && !root->right) {
		if (cur_lev > *max)
			*max = cur_lev;
	}

	return *max;
}

int maxDepth(struct TreeNode* root) {
	int max = 0;

	if (!root)
		return 0;

	travel_tree(root, 0, &max);

	return max;
}
	    
int  main(int argc, char **argv) 
{
	struct TreeNode *tr = NULL;
	int max;
	int i;
	int val[10] = {49, 15, 86, 79, 93, 35, 12, 92, 21, 77};

	for(i = 0; i < 10; i++) {
		tr = insert_value(tr, val[i]);
	}	
	
	print_sorted_tree(tr);
	printf("\n");
	
	max = maxDepth(tr);
	printf("max depth = %d\n", max);

	return 0;
}
