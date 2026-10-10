/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;
    if (!root) return NULL;

    int **ans = malloc(2000 * sizeof(int*));
    *returnColumnSizes = malloc(2000 * sizeof(int));
    struct TreeNode *q[20000];
    int f = 0, r = 0;
    q[r++] = root;

    while (f < r) {
        int n = r - f;
        ans[*returnSize] = malloc(n * sizeof(int));
        (*returnColumnSizes)[*returnSize] = n;

        for (int i = 0; i < n; i++) {
            struct TreeNode *t = q[f++];
            ans[*returnSize][i] = t->val;
            if (t->left) q[r++] = t->left;
            if (t->right) q[r++] = t->right;
        }
        (*returnSize)++;
    }
    return ans;
}