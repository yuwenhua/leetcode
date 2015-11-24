/*
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as a binary 
 * tree in which the depth of the two subtrees of every node never differ 
 * by more than 1.
 *
 * https://leetcode.com/problems/balanced-binary-tree/
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>


/*
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

#define MAX(a,b) ((a>b)?a:b)


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
int __isBalanced(struct TreeNode* root) {
	int left, right, diff;

	if (!root)
		return 0;

	right = __isBalanced(root->right);
	left = __isBalanced(root->left);
	if (right == -1 || left == -1)
		return -1;

	diff = (right > left) ? right - left : left -right;
	if (diff > 1)
		return -1;
	else 
		return 1 + MAX(left, right);

}

bool isBalanced(struct TreeNode* root) {
	return !(__isBalanced(root) == -1);
}
int  main(int argc, char **argv) 
{
	struct TreeNode *tr = NULL;
	int i;
	int val[] = {49, 15, 86, 79, 93, 35, 12, 92, 21, 77};
	bool balanced = false;

	for(i = 0; i < 10; i++) {
		tr = insert_value(tr, val[i]);
	}	
	print_sorted_tree(tr);
	printf("\n");

	balanced = isBalanced(tr);
	printf("is tree balanced? %d\n", balanced);

	return 0;
}

