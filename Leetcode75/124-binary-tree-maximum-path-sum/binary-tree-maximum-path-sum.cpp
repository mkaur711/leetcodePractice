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
    int maxPathSum(TreeNode* root) {
        int globalMax = INT_MIN; // To store the maximum path sum
        findMaxPath(root, globalMax);
        return globalMax;
    }

private:
    // Helper function to calculate the max path sum through each node
    int findMaxPath(TreeNode* node, int& globalMax) {
        if (!node) return 0; // Base case: null node contributes 0

        // Recursively compute max path sum from left and right subtrees
        int leftMax = max(0, findMaxPath(node->left, globalMax)); // Ignore negative contributions
        int rightMax = max(0, findMaxPath(node->right, globalMax)); // Ignore negative contributions

        // Update global maximum if the current path is greater
        globalMax = max(globalMax, node->val + leftMax + rightMax);

        // Return max path sum that can be extended upwards
        return node->val + max(leftMax, rightMax);
    }
};