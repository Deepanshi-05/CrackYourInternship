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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
        int levelSize = q.size();  // Number of nodes at the current level
        vector<int> currentLevel; 
         for (int i = 0; i < levelSize; i++) {
            TreeNode* current = q.front();
            q.pop();

            currentLevel.push_back(current->val);
            if(current->left){
               q.push(current->left);
            }
            if(current->right){
                q.push(current->right);
            }
        }
        result.push_back(currentLevel);
        }
        return result;
    }
};