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
        int res = 0;
        bool found = false;
        auto in_order = [&](auto &self, TreeNode* node) {
            if(node == nullptr || found) return;
            self(self, node->left);
            if(--k == 0) {
                res = node->val;
                found = true;
                return;
            } 
            self(self, node->right);
        };
        in_order(in_order, root);
        return res;
    }
};