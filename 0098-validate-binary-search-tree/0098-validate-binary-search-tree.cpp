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
    bool isValidBST(TreeNode* root) {
        auto dfs = [&](auto &self, TreeNode * p, long left, long right) {
            if(p == nullptr) return true;
            if(!(p->val < right && p->val > left)) return false;
            return self(self, p->left, left, p->val) && self(self, p->right, p->val, right);
        };
        return dfs(dfs, root, LONG_MIN, LONG_MAX);
    }
};