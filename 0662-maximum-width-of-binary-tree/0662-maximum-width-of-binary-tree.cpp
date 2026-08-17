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
    int widthOfBinaryTree(TreeNode* root) {
        // vector<vector<int>> m;
        // auto f = [&](auto &self, TreeNode* node, int layer, unsigned long long idx) {
        //     if(!node) return;
        //     if(m.size() == layer) m.resize(m.size() + 1);
        //     m[layer].push_back(idx);
        //     self(self, node->left, layer + 1, idx * 2 + 1);
        //     self(self, node->right, layer + 1, idx * 2 + 2);
        // };
        // f(f, root, 0, 0);
        // int maximum = 0;
        // for(int i = 0; i < m.size(); i++) {
        //     int size = m[i].size();
        //     int width = size == 1 ? 1 : m[i][size - 1] - m[i][0] + 1;
        //     maximum = max(maximum, width);
        // }
        // return maximum;
        unsigned long long maximum = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        while(!q.empty()) {
            int size = q.size();
            unsigned long long base = q.front().second;
            unsigned long long lastIdx = 0;

            for(int i = 0; i < size; i++) {
                auto [cur, idx] = q.front();
                q.pop();
                idx -= base;
                lastIdx = idx;
                if(cur->left) q.push({cur->left, idx * 2 + 1});
                if(cur->right) q.push({cur->right, idx * 2 + 2});
            }
            maximum = max(maximum, lastIdx + 1);
        }
        return maximum;
    }
};