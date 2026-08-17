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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        auto f = [&](auto &self, TreeNode* node1, TreeNode* node2) {
            if(!node1 && !node2) return true;
            if((node1 == nullptr && node2 != nullptr) || (node1 != nullptr && node2 == nullptr)) return false;
            if(node1->val != node2->val) return false;
            if(!self(self, node1->left, node2->left) || !self(self, node1->right, node2->right)) return false;
            return true;
        };
        return f(f, p, q);
    }
};