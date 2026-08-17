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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> tmp;
        auto dfs = [&](auto &self, TreeNode* node, int curSum) -> void {
            if(curSum == targetSum && !node->left && !node->right) res.push_back(tmp);
            if(node->left) {
                tmp.push_back(node->left->val);
                self(self, node->left, curSum + node->left->val);
                tmp.pop_back();
            }
            if(node->right) {
                tmp.push_back(node->right->val);
                self(self, node->right, curSum + node->right->val);
                tmp.pop_back();
            }
        };
        tmp.push_back(root->val);
        dfs(dfs, root, root->val);
        return res;
    }
};