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
TreeNode* binarytree(vector<int>& inorder, vector<int>& postorder,int start,int right,int& last){
    if(start>right || last<0){
        return NULL;
    }
    TreeNode* root = new TreeNode(postorder[last]);
    last--;

    int i = start;
    for(i = start; i<= right; i++){
        if(inorder[i] == root->val){
            break;
        }
    }

    // Build right subtree first (postorder goes from right to left)
    root->right = binarytree(inorder, postorder, i + 1, right, last);

    // Build left subtree
    root->left = binarytree(inorder, postorder, start, i - 1, last);

    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       int last = postorder.size()-1;
       int start = 0;
       return binarytree(inorder,postorder,start,inorder.size()-1,last); 
    }
};