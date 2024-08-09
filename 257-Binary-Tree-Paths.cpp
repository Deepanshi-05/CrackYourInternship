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

void binaryTree(TreeNode* root,string currentpath, vector<string>& path){
    if(root == NULL){
        return;
    }
    currentpath += to_string(root->val);
    if(root->left == NULL && root->right == NULL){
        path.push_back(currentpath);
    }
    else{
        currentpath += \->\;
        binaryTree(root->left, currentpath, path);
        binaryTree(root->right,currentpath,path);
    }
}
    vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> path;
    if (root != nullptr) {
        binaryTree(root, \\, path);
    }
    return path;
      
    }
};