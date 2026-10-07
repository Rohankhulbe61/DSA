/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root== NULL){
        return NULL;
    };
if(key< root->val){
    root->left=deleteNode(root->left,key);
}
else if(key>root->val){
    root->right=deleteNode(root->right,key);
}
else{
    if(root->left==NULL){
        struct TreeNode* temp= root->right;
        free(root);
        return temp;
    }
    if(root->right==NULL){
        struct TreeNode* temp= root->left;
        free(root);
        return temp;
    }
    struct TreeNode* successor=root->right;
    while(successor->left!= NULL){
        successor= successor->left;
    }
    root->val= successor->val;
    root->right=  deleteNode(root->right,successor->val);
    }
return root;
}