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
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true; // Empty tree is complete

        queue<TreeNode*> q;
        q.push(root);

        bool encounteredNull = false;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                encounteredNull = true; // Null node encountered
            } else {
                if (encounteredNull) return false; // Nodes after null are invalid
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};