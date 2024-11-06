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
    int closestValue(TreeNode* root, double target) {
        TreeNode* node = root;
        int closest_val = root->val;
        double smallest_diff = std::numeric_limits<double>::max();
        while(node)
        {
            auto const diff = std::abs(node->val - target);
            if(diff < smallest_diff)
            {
                closest_val = node->val;
                smallest_diff = diff;
            }
            else if(diff == smallest_diff)
            {
                closest_val = std::min(closest_val, node->val);
            }
            node = target > node->val ? node->right : node->left;
        }
        return closest_val;
    }
};