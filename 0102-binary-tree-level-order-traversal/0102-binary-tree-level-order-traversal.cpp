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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res; 
        auto f = [&](auto &self, TreeNode* node, int layer) {
            if(!node) return -1001;
            int left = self(self, node->left, layer + 1);
            int right = self(self, node->right, layer + 1);
            
            if (left != -1001 || right != -1001) {
                if ((int)res.size() <= layer) res.resize(layer + 1);
            }

            if(left != -1001) res[layer].push_back(left);
            if(right != -1001) res[layer].push_back(right);
            return node->val;
        };
        res.resize(1);
        res[0].push_back(root->val);
        f(f, root, 1);
        return res;
    }
};