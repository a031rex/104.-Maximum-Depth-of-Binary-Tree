
#include "stdio.h"
#include "stdlib.h"


/*

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
typedef struct TreeNode node;

int maxDepth(struct TreeNode* root) {
    if(!root)
    	return 0;
    int lmax = maxDepth(root->left);
    int rmax = maxDepth(root->right);

    return lmax>=rmax? (lmax+1):(rmax+1);
}

void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->val = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->val)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->val)
    {
        insert(&(*tree)->right, val);
    }

}


void main()
{
    node *root;


    root = NULL;
    /* Inserting nodes into tree */
    insert(&root, 9);
    insert(&root, 4);
    insert(&root, 15);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 17);
    insert(&root, 2);
    int depth = maxDepth(root);
    printf("Max depth = %d\n",depth);
}

