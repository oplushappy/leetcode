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
        vector<vector<int>> m;
        auto f = [&](auto &self, TreeNode* node, int layer, unsigned long long idx) {
            if(!node) return;
            if(m.size() == layer) m.resize(m.size() + 1);
            m[layer].push_back(idx);
            self(self, node->left, layer + 1, idx * 2 + 1);
            self(self, node->right, layer + 1, idx * 2 + 2);
        };
        f(f, root, 0, 0);
        int maximum = 0;
        for(int i = 0; i < m.size(); i++) {
            int size = m[i].size();
            int width = size == 1 ? 1 : m[i][size - 1] - m[i][0] + 1;
            maximum = max(maximum, width);
        }
        return maximum;
                // int maximum = 0;
        // auto bfs = [&](TreeNode* node) {
        //     deque<TreeNode*> q;
        //     q.push_back(node);
        //     while(!q.empty()) {
        //         // if(!q.front() && !q.back()) break;
        //         while(!q.front()) q.pop_front();
        //         while(!q.back()) q.pop_back();
                
        //         int size = q.size();
        //         int layer = 0;
                
        //         for(int i = 0; i < size; i++) {
        //             TreeNode* cur = q.front();
        //             q.pop_front();
        //             if(cur->left) q.push_back(cur->left);
        //             if(cur->left) q.push_back(cur->left);
        //         }
        //         maximum = max(maximum, layer);
        //     }
        // };
        // bfs(root);
        // return maximum; 
    }
};