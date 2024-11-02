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
int minDiff = INT_MAX;
TreeNode* prev = nullptr;

void inorder(TreeNode* root){
    if(!root) return;

    //Traverse the left subtree
    inorder(root->left);

    if(prev != nullptr){
        minDiff = min(minDiff, root->val - prev->val);
    }

    prev = root;

    //Traverse the right subtree
    inorder(root->right);
}
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};