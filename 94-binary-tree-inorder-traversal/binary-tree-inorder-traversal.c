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
void inorder(struct TreeNode* root, int* ans, int* size) {
    if (root==NULL)
        return;
    inorder(root->left,ans,size);
    ans[*size]=root->val;
    (*size)++;
    inorder(root->right,ans,size);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans=malloc(100*sizeof(int));
    *returnSize=0;
    inorder(root,ans,returnSize);
    return ans;
}