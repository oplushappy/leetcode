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
    bool isBalanced(TreeNode* root) {
        bool flag = false;
        auto f = [&](auto &self, TreeNode* node) {
            if(!node) return 0;
            int height = 1;
            int left = self(self, node->left);
            int right = self(self, node->right);
            if(abs(left - right) <= 1) return height + max(left, right);
            else flag = true;
            return 0;
        };
        f(f, root);
        return flag ? false : true;
    }
};