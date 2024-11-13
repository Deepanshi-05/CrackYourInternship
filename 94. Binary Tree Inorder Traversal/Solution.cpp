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
    vector<int> inorderTraversal(TreeNode* root) {
         vector<int>ans;
        while(root){
            if(!root->left){
                ans.push_back(root->val);
                root=root->right;
            }
            else{
                TreeNode* c = root->left;
                while(c->right&&c->right!=root){
                    c=c->right;
                }
                //traversed
                if(c->right==root){
                    ans.push_back(root->val);
                    c->right=NULL;
                    root=root->right;
                }
                // Not traversed
                else{
                    c->right=root;
                    root=root->left;
                }
            }
        }
        return ans;
    }
};