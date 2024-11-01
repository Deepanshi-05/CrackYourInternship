/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
          if (!root) return nullptr;

        // Initialize a queue for level order traversal
        std::queue<Node*> q;
        q.push(root);

        // Process each level
        while (!q.empty()) {
            int level_size = q.size();  // Number of nodes at the current level
            Node* prev = nullptr;       // Pointer to the previous node at this level

            // Traverse all nodes in the current level
            for (int i = 0; i < level_size; ++i) {
                Node* node = q.front();
                q.pop();

                // Connect the previous node's `next` pointer to the current node
                if (prev) {
                    prev->next = node;
                }
                prev = node;  // Update prev to the current node

                // Enqueue the left and right children of the current node
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Set the `next` pointer of the last node in the level to NULL
            if (prev) {
                prev->next = nullptr;
            }
        }

        return root;
    }
};