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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto LCA = [&](auto &self, TreeNode* node) -> TreeNode* {
            if(!node || node == p || node == q) return node;
            TreeNode* left = self(self, node->left);
            TreeNode* right = self(self, node->right);
            if(left && right) return node;
            return left ? left : right;
        };
        return LCA(LCA, root);
    }
};