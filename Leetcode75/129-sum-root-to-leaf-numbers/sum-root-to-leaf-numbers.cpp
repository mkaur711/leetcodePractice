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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
private:
    int dfs(TreeNode* node, int currentSum) {
        if (node == nullptr) {
            return 0;
        }
        
        // Update current path sum
        currentSum = currentSum * 10 + node->val;
        
        // If it's a leaf node, return the current path sum
        if (node->left == nullptr && node->right == nullptr) {
            return currentSum;
        }
        
        // Recurse down the left and right children
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
};