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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result; // Vector to store the right side view
    if (!root) return result; // If the root is null, return an empty vector

    queue<TreeNode*> q; // Queue for BFS
    q.push(root); // Start with the root node

    while (!q.empty()) {
        int levelSize = q.size(); // Number of nodes at the current level
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front(); // Get the front node
            q.pop(); // Remove it from the queue

            // If it's the last node in this level, add its value to the result
            if (i == levelSize - 1) {
                result.push_back(node->val);
            }

            // Add the right and left children to the queue
            if (node->left) q.push(node->left);
                        if (node->right) q.push(node->right);

        }
    }

    return result; // Return the final result
    }
};