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
        if(!root) return res;
        auto bfs = [&](TreeNode* node) {
            queue<TreeNode*> q;
            q.push(node);
            while(!q.empty()) {
                int size = q.size();
                vector<int> tmp;
                for(int i = 0; i < size; i++) {
                    TreeNode* cur = q.front();
                    q.pop();
                    tmp.push_back(cur->val);
                    if(cur->left) q.push(cur->left);
                    if(cur->right) q.push(cur->right);
                }
                res.push_back(tmp);
            }
        };
        bfs(root);
        return res;
    }
};