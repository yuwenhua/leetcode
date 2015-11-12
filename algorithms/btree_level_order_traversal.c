/*
 * Given a binary tree, return the level order traversal of its nodes'
 * values. (ie, from left to right, level by level).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *   9  20
 *  /  \
 * 15   7
 * return its level order traversal as:
 * [
 *  [3],
 *  [9,20],
 *  [15,7]
 * ]
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
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
void travel_tree(struct TreeNode *root, 
		int prev_lev, 
		int **columnSizes,
		int *returnSize,
		int **level) {
	int cur_lev;

	if(!root)
		return;

	cur_lev = prev_lev + 1;
	if(cur_lev > *returnSize) {
		(*returnSize)++;
		level[cur_lev-1]=(int *)calloc(1024, sizeof(int));
	}
	(*columnSizes)[cur_lev-1]++; 
	level[cur_lev-1][(*columnSizes)[cur_lev-1]-1] = root->val;

	if(root->left) {
		travel_tree(root->left, cur_lev, columnSizes, returnSize, level);
	}
	if(root->right) {
		travel_tree(root->right, cur_lev, columnSizes, returnSize, level);
	}
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, 
 * assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int **level = NULL;
	
	if(!root)
		return NULL;
	
	level = (int **)calloc(1024, sizeof(int*));
	*columnSizes = (int *)calloc(1024, sizeof(int));

	travel_tree(root, 0, columnSizes, returnSize, level);

	return level;

}
int  main(int argc, char **argv) 
{
	struct TreeNode *tr = NULL;
	int i,j;
	int val[10] = {49, 15, 86, 79, 93, 35, 12, 92, 21, 77};
	int **level = NULL;
	int *columnSizes;
	int returnSize = 0;

	tr = NULL;
	
	for(i = 0; i < 10; i++) {
		tr = insert_value(tr, val[i]);
	}	
	
	print_sorted_tree(tr);
	printf("\n");
	
	returnSize = 0;
	level = levelOrder(tr, &columnSizes, &returnSize);
	printf("array size = %d\n", returnSize);
	for(i = 0; i < returnSize; i++) {
		for(j = 0; j < columnSizes[i]; j++) {
			printf("%d ", level[i][j]);
		}
		printf("\n");
	}

	return 0;
}

