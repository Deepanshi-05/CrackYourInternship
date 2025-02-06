//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
     Node* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int& preIndex, 
                          int inStart, int inEnd, unordered_map<int, int>& inMap) {
        if (inStart > inEnd) return NULL;

        // Get the current root value from preorder traversal
        int rootVal = preorder[preIndex++];
        Node* root = new Node(rootVal);

        // Find the index of rootVal in inorder traversal
        int inIndex = inMap[rootVal];

        // Recursively construct left and right subtrees
        root->left = buildTreeHelper(preorder, inorder, preIndex, inStart, inIndex - 1, inMap);
        root->right = buildTreeHelper(preorder, inorder, preIndex, inIndex + 1, inEnd, inMap);

        return root;
    }


    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        unordered_map<int, int> inMap;  // Store inorder value-index mapping for quick access
        int n = inorder.size();  // Get the size dynamically

        for (int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }

        int preIndex = 0;
        return buildTreeHelper(preorder, inorder, preIndex, 0, n - 1, inMap);

    }
    
    
    void postorderTraversal(Node* root) {
    if (!root) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data<< " ";
}
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends