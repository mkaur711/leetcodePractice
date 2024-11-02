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
    vector<vector<int>> verticalOrder(TreeNode* root) {
         vector<vector<int>> output;
        if (root == nullptr) {
            return output;
        }

        // Map to store nodes by column indices
        map<int, vector<int>> columnTable;
        // Queue for BFS traversal, storing node and column information
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0}); // Start with root at column 0

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            
            TreeNode* node = front.first;
            int column = front.second;

            if (node != nullptr) {
                // Add the node's value to the column's list
                columnTable[column].push_back(node->val);

                // Add left and right children with their column indices
                q.push({node->left, column - 1});
                q.push({node->right, column + 1});
            }
        }

        // Extract columns in sorted order
        for (auto& [col, nodes] : columnTable) {
            output.push_back(nodes);
        }

        return output;
    }
};