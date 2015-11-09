/*
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf 
 * path such that adding up all the values along the path equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \      \
 *         7    2      1
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 *
 * https://leetcode.com/problems/path-sum/
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

int travel_tree(struct TreeNode *root, int parent_sum, int sum, bool *result) {
	int cur_sum;

	if(!root)
		return 0;
	if(*result == true)
		return 0;
	
	cur_sum = parent_sum + root->val;

	if(root->left) {
		travel_tree(root->left, cur_sum, sum, result);
	}
	if(root->right) {
		travel_tree(root->right, cur_sum, sum, result);
	}
	if(!root->left && !root->right) {
		if (cur_sum == sum)
			*result = true;
	}

	return 0;
}

bool hasPathSum(struct TreeNode* root, int sum) {
	bool result = false;

	if (!root)
		return 0;
	travel_tree(root, 0, sum, &result);

	return result;

}
int  main(int argc, char **argv) 
{
	struct TreeNode *tr = NULL;
	int i;
	int val[10] = {49, 15, 86, 79, 93, 35, 12, 92, 21, 77};
	bool result;
	int sum[] = {76,100,120,200,291,300,320,400}; 

	tr = NULL;
	
	for(i = 0; i < 10; i++) {
		tr = insert_value(tr, val[i]);
	}	
	
	print_sorted_tree(tr);
	printf("\n");
	for(i = 0; i < 8; i++) {
		
		result = hasPathSum(tr, sum[i]);
		printf("result %d ? %d\n", sum[i], result);
	}

	return 0;
}
