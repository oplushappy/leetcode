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
    int pathSum(TreeNode* root, int targetSum) {
        // vector<vector<int>> res;
        // vector<int> tmp;
        int res = 0;
        auto dfs = [&](auto &self, TreeNode* node, long long curSum) -> void {
            if(!node) return;
            int cur = node->val;
            curSum += cur;
            // tmp.push_back(cur);

            if(curSum == targetSum) {
                // res.push_back(tmp);
                res += 1;
            }
            self(self, node->left, curSum);
            self(self, node->right, curSum);
        
            // tmp.pop_back();
        };
        auto traverse = [&](auto &self, TreeNode* node)-> void {
            if(!node) return;
            // tmp = {};
            dfs(dfs, node, 0);
            self(self, node->left);
            self(self, node->right);
        };
        traverse(traverse, root);
        return res;
        // return res.size();
    }
};