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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        auto judge = [](auto &self, TreeNode* p, TreeNode* q) {
            if(!p && !q) return true;
            if(!p || !q) return false;
            if(p->val != q->val) return false;
            return self(self, p->left, q->left) && self(self, p->right, q->right);
        };
        auto traverse = [&](auto &self, TreeNode* node1, TreeNode* node2) {
            if(!node1) return false;
            if(node1->val == node2->val) {
                if(judge(judge, node1, node2)) return true;
            };
            bool left = self(self, node1->left, node2);
            bool right = self(self, node1->right, node2);
            if(left || right) return true;
            return false;
        };
        return traverse(traverse, root, subRoot);
    }
};