/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void postorder(struct TreeNode* root, int* ans, int* size) {
    if (root==NULL)
        return;
    postorder(root->left,ans,size);
    postorder(root->right,ans,size);
    ans[*size]=root->val;
    (*size)++;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans=malloc(100*sizeof(int));
    *returnSize=0;
    postorder(root,ans,returnSize);
    return ans;
}