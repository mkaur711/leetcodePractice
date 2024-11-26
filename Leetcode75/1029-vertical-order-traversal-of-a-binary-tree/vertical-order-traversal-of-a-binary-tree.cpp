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
    // Helper function to perform DFS
void dfs(TreeNode* node, int row, int col, map<int, priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<>>>& nodes) {
    if (!node) return;

    // Add the node to the map with its row and value
    nodes[col].emplace(row, node->val);

    // Traverse left and right subtrees with updated positions
    dfs(node->left, row + 1, col - 1, nodes);
    dfs(node->right, row + 1, col + 1, nodes);
}

// Main function for vertical order traversal
vector<vector<int>> verticalTraversal(TreeNode* root) {
    // Map to hold nodes grouped by columns
    map<int, priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<>>> nodes;

    // Perform DFS
    dfs(root, 0, 0, nodes);

    // Prepare the result
    vector<vector<int>> result;
    for (auto& [col, pq] : nodes) {
        vector<int> colNodes;
        while (!pq.empty()) {
            colNodes.push_back(get<1>(pq.top()));
            pq.pop();
        }
        result.push_back(colNodes);
    }
    return result;
}

};