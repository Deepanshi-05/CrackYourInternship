/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return false;
        }

        // Check if it's a leaf node and if the path sum equals targetSum
        if (root->left == NULL && root->right == NULL) {
            return (targetSum == root->val);
        }

        // Recursively check the left and right subtrees with the updated target
        // sum
        int newTarget = targetSum - root->val;
        return hasPathSum(root->left, newTarget) ||
               hasPathSum(root->right, newTarget);
    }
};