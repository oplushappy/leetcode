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
    bool isSymmetric(TreeNode* root) {
        auto f = [&](auto &self, TreeNode* p, TreeNode* q) {
            if(!p && !q) return true;
            if(!p || !q) return false;
            if(p->val != q->val) return false;
            if(!self(self, p->left, q->right)) return false;
            if(!self(self, p->right, q->left)) return false;
            return true;
        };
        return f(f, root->left, root->right);
    }
};