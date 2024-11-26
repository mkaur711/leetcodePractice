/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool foundP = false, foundQ = false; // Flags to check existence of p and q

    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr; // Base case: null node

        TreeNode* left = findLCA(root->left, p, q);  // Search in the left subtree
        TreeNode* right = findLCA(root->right, p, q); // Search in the right subtree

        if (root == p) { foundP = true; return root; } // Mark p as found
        if (root == q) { foundQ = true; return root; } // Mark q as found

        // If both left and right are non-null, current node is the LCA
        if (left && right) return root;

        // Otherwise, return the non-null subtree
        return left ? left : right;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        foundP = false; foundQ = false; // Reset flags
        TreeNode* lca = findLCA(root, p, q);

        // If either p or q is missing, return null
        if (!foundP || !foundQ) return nullptr;

        return lca;
    }
};