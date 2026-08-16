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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        auto f = [&](auto &self, int l, int r, int idx)-> TreeNode* {
            if(l > r) return nullptr;
            
            int cur = preorder[idx];
            TreeNode* node = new TreeNode(cur);
            
            int index = find(inorder.begin() + l, inorder.begin() + r + 1, cur) - inorder.begin();
            int leftSize = index - l;

            node->left = self(self, l, index - 1, idx + 1);
            node->right = self(self, index + 1, r, idx + leftSize + 1);
            return node;
        };
        return f(f, 0, preorder.size() - 1, 0);
    }
};