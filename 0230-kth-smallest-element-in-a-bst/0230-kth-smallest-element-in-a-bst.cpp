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
    int kthSmallest(TreeNode* root, int k) {
        int tk = 0;
        int res = 0;
        auto post_order = [&](auto &self, TreeNode* node) {
            if(node == nullptr) return;
            self(self, node->left);
            tk++;
            if(tk == k) res = node->val;
            self(self, node->right);
        };
        post_order(post_order, root);
        return res;
    }
};