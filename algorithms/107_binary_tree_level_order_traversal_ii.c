/*
 * Given a binary tree, return the bottom-up level order traversal of its nodes' 
 * values. (ie, from left to right, level by level from leaf to root).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *         3
 *        / \
 *       9  20
 *      /  \
 *     15   7
 * return its bottom-up level order traversal as:
 * [
 *  [15,7],
 *  [9,20],
 *  [3]
 * ]
 * 
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

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

int add_level_node(struct TreeNode *root, 
		int level, 
		struct TravelTreeResult *result) {
	struct ListNode *node = (struct ListNode *)calloc(1, sizeof(struct ListNode));
	
	if(level >= result->limit){
		printf("level overflow.\n");
		//malloc more memory, move data to new place; or just return fail :D
		return -1;
	}
	
	node->val = root->val;
	node->next = result->tree[level].node;

	result->tree[level].node = node;

	return 0;
}

void travel_tree(struct TreeNode *root, 
		int level,
		struct TravelTreeResult *result) {

	if(!root)
		return;

	add_level_node(root, level, result);

	if(root->right) {
		travel_tree(root->right, level+1, result);
	}
	if(root->left) {
		travel_tree(root->left, level+1, result);
	}
}
struct TravelTreeResult *init_ttr() {
	struct TravelTreeResult	*result;

	result = (struct TravelTreeResult *)calloc(1, sizeof(struct TravelTreeResult));
	result->tree = (struct TreeLevel *)calloc(1024, sizeof(struct TreeLevel));
	result->limit = 1024;
	return result;
}
/*
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, 
 * assume caller calls free().
 */
int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
	int **level = NULL;
	struct TravelTreeResult *result; 
	int i,j,depth;

	if(!root)
		return NULL;

	result = init_ttr();
	travel_tree(root, 0, result);
	level = (int **)calloc(1024, sizeof(int*));
	*columnSizes = (int *)calloc(1024, sizeof(int));

	for(depth = 0; depth < result->limit; depth++) {
		if(result->tree[depth].node == NULL)
			break;
		level[depth] = (int *)calloc(1024, sizeof(int));
	}
	for(i = depth-1; i >= 0; i--){
		j = 0;
		while(result->tree[i].node) {
			level[depth-1 - i][j] = result->tree[i].node->val;
			(*columnSizes)[depth-1-i]++;
			j++;
			result->tree[i].node = result->tree[i].node->next;
		}
	}
	*returnSize = depth;
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
	level = levelOrderBottom(tr, &columnSizes, &returnSize);
	printf("array size = %d\n", returnSize);
	for(i = 0; i < returnSize; i++) {
		for(j = 0; j < columnSizes[i]; j++) {
			printf("%d ", level[i][j]);
		}
		printf("\n");
	}

	return 0;
}

