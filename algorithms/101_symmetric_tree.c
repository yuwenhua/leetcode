/*
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric 
 * around its center).
 *
 * For example, this binary tree is symmetric:
 *
 *         1
 *        / \
 *       2   2
 *      / \ / \
 *     3  4 4  3
 * But the following is not:
 *         1
 *        / \
 *       2   2
 *        \   \
 *        3    3
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 *
 * https://leetcode.com/problems/symmetric-tree/
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

int is_symmetric(struct TreeNode *left, struct TreeNode *right) {
	if(!left && !right)
		return 1;
	if(!left || !right || left->val != right->val)
		return 0;
	return is_symmetric(left->right,right->left) 
		& is_symmetric(left->left,right->right);
}

bool isSymmetric(struct TreeNode *root) {

	if(!root)
		return true;
	return is_symmetric(root->left,root->right);
}


int  main(int argc, char **argv) 
{
	struct TreeNode *tr = NULL;
	int i;
	int val[] = {1,1,1,1,1,1,1};
	bool result = false;

	tr = NULL;
	
	for(i = 0; i < 7; i++) {
		tr = insert_value(tr, val[i]);
	}	
	
	print_sorted_tree(tr);
	printf("\n");
	
	result = isSymmetric(tr);
	printf("Is this tree  symmetric? %d\n", result);

	return 0;
}


