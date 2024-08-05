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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        if(root == NULL){
            return 0;
        }
        if(low <= root->val && root->val <= high){
            sum = sum + root->val;
        }
        if (low < root->val) {
        sum += rangeSumBST(root->left, low, high);
    }

    // Recursively call the function for the right subtree if the right child might have values within the range
    if (root->val < high) {
        sum += rangeSumBST(root->right, low, high);
    }
        return sum;
    }
};