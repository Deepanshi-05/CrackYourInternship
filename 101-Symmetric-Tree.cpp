/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool isMirror(TreeNode* left, TreeNode* right){
    if(left == NULL && right == NULL){
        return true;
    }
    if(left == NULL || right == NULL){
        return false;
    }

    return (left->val == right->val)
    && isMirror(left->left, right->right) &&
    isMirror(left->right, right->left);
}
    bool isSymmetric(TreeNode* root) {
        TreeNode* left = root->left;
        TreeNode* right =  root->right;
        if(root == NULL){
            return true;
        }
        return isMirror(left, right);
    }
};