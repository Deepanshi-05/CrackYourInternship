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
    void flatten(TreeNode* root) {
          if (!root) return;

        std::stack<TreeNode*> stack;
        stack.push(root);

        while (!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();

            // Push right child first so that left child is processed first
            if (node->right) stack.push(node->right);
            if (node->left) stack.push(node->left);

            // Set the current node's right to the next node in preorder (top of stack)
            if (!stack.empty()) {
                node->right = stack.top();
            }
            
            // Set left to NULL as per the problem requirement
            node->left = nullptr;
        }
    }
};