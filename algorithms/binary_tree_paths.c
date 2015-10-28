/*
 * Given a binary tree, return all root-to-leaf paths.
 *
 * For example, given the following binary tree:
 *
 *	     1
 *     /   \
 *    2     3
 *     \
 *      5
 *    All root-to-leaf paths are:
 *    ["1->2->5", "1->3"]
 *    Credits:
 *    Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 * 
 * https://leetcode.com/problems/binary-tree-paths/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

/* By Vamei */
/* binary search tree */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct TreeNode {
	struct TreeNode* parent;
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};


bool is_root(struct TreeNode* np)
{
	if(np->parent == NULL) 
		return true;
	return false;
}

bool is_leaf(struct TreeNode* np)
{
	if (np->left == NULL && np->right == NULL)
		return true;
	return false;
}

int delete_leaf(struct TreeNode* np)
{
	int val;
	struct TreeNode* parent;
	val = np->val;
	parent  = np->parent;
	if(!is_root(np)) {
		if (parent->left == np) {
			parent->left = NULL;
		}
		else {
			parent->right = NULL;
		}
	}
	free(np);
	return val;
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

int delete_TreeNode(struct TreeNode* np) 
{
	struct TreeNode* replace;
	int val;
	if (is_leaf(np)) {
		return delete_leaf(np);
	}   
	else {
		/* if a TreeNode is not a leaf, then we need to find a replacement */
		replace = (np->left != NULL) ? find_max(np->left) : find_min(np->right);
		val = np->val;
		np->val = delete_TreeNode(replace);
		return val;
	}
}

void insert_TreeNode_to_nonempty_tree(struct TreeNode *tr, struct TreeNode* np)
{
	/* insert the TreeNode */
	if(np->val <= tr->val) {
		if (tr->left == NULL) {
			/* then tr->left is the proper place */
			tr->left = np;
			np->parent = tr;
			return;
		}
		else {
			insert_TreeNode_to_nonempty_tree(tr->left, np);
		}
	}
	else if(np->val > tr->val) {
		if (tr->right == NULL) {
			tr->right = np;
			np->parent = tr;
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
	np->parent  = NULL;
	np->left  = NULL;
	np->right  = NULL;

	if (tr == NULL) tr = np;
	else {
		insert_TreeNode_to_nonempty_tree(tr, np);
	}
	return tr;
}

void travel_tree(struct TreeNode *node,	
		char **s, 
		char *s_parent,
		int *size) {

	char new_parent[1024];

	memset(new_parent, 0, 1024);
	if(strlen(s[*size]) == 0) {
		sprintf(s[*size], "%d", node->val);
	}
	else {
		sprintf(s[*size], "%s->%d", s_parent, node->val);
	}
	strcpy(new_parent, s[*size]);
	
	if(node ->left) {
		travel_tree(node->left, s, new_parent,  size);
	}
	if(node->right) {
		if(node->left) {
			*size += 1;
			s[*size] = (char*)calloc(sizeof(char), 1024);
			strcpy(s[*size], new_parent);
		}
		travel_tree(node->right, s, new_parent,  size);
	}

	return ;
}

char** binaryTreePaths(struct TreeNode *root, int *returnSize) {
	char **result;

	if(!root) {
		returnSize = 0;
		return NULL;
	}

	// how much leaf will there be?
	result = (char **)calloc(sizeof(char*), 1024); 

	*returnSize = 0;
	result[0] = (char*)calloc(sizeof(char), 1024);
	travel_tree(root, result, result[0], returnSize);

	*returnSize += 1;
	return result;
}
int  main(int argc, char **argv) 
{
	struct TreeNode *tr = NULL;
	int i;
	int val[10] = {49, 15, 86, 79, 93, 35, 12, 92, 21, 77};
	int returnSize = 0;
	char **result;

	tr = NULL;
	
	for(i = 0; i < 10; i++) {
		tr = insert_value(tr, val[i]);
	}	
	
	print_sorted_tree(tr);
	printf("\n");

	result = binaryTreePaths(tr, &returnSize);
	
	for(i = 0; i < returnSize; i++) {
		printf("%s\n", result[i]);
	}
	/*
	np = find_value(tr, 45);
	if(np != NULL) {
		delete_TreeNode(np);
		//printf("After deletion:\n");
		print_sorted_tree(tr);
	}
	*/
	return 0;
}

