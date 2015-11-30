/**
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of
 * two given nodes in the BST.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor 
 * is defined between two nodes v and w as the lowest node in T that has both v 
 * and w as descendants (where we allow a node to be a descendant of itself).”
 *
 *         _______6______
 *        /              \
 *    ___2__          ___8__
 *   /      \        /      \
 *  0      _4       7       9
 *        /  \
 *       3   5
 * For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. 
 * Another example is LCA of nodes 2 and 4 is 2, since a node can be a 
 * descendant of itself according to the LCA definition.
 *
 *  https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

/**
 *  Definition for a binary tree node.
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

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	struct TreeNode *tmp, *lca;

	if(p->val > q->val) {
		tmp = p;
		p = q;
		q = tmp;
	}

	lca = root;
	while(!(p->val <= lca->val && q->val >= lca->val)) {
		if(lca->val > q->val) {
			lca = lca->left;
		}
		else if(lca->val < q->val) {
			lca = lca->right;
		}
	}
	return lca;
	
}

int  main(int argc, char **argv) 
{
	struct TreeNode *tr1 = NULL, *lca = NULL;
	int i;
	int val_1[10] = {49, 15, 86, 79, 93, 35, 12, 92, 21, 77};

	for(i = 0; i < 10; i++) {
		tr1 = insert_value(tr1, val_1[i]);
	}	
	
	print_sorted_tree(tr1);
	printf("\n");
	
	lca = lowestCommonAncestor(tr1, tr1->left->left, tr1->left->right);
	print_sorted_tree(lca);
	printf("\n");

	return 0;
}

