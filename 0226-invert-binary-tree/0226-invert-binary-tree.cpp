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
    TreeNode* invertTree(TreeNode* root) {
        auto invert = [&](auto &self, TreeNode* node) -> TreeNode* {
            if(!node) return nullptr;
            TreeNode* tmp = node->left;
            node->left = self(self, node->right);
            node->right = self(self, tmp);
            return node;
        };
        return invert(invert, root);
    }
};