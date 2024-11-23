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
    // Recursive helper function for in-order traversal
    void inorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return; // Base case: if node is null, return
        inorder(node->left, result); // Recur on the left subtree
        result.push_back(node->val); // Process the current node
        inorder(node->right, result); // Recur on the right subtree
    }

    // Main function to initiate in-order traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result); // Start recursive traversal
        return result;
    }
};