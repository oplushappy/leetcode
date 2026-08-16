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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        
        auto bfs = [&](TreeNode* node) -> void {
            queue<TreeNode*> q;
            q.push(node);
            while(!q.empty()) {
                int size = q.size();
                for(int i = 0; i < size; i++) {
                    TreeNode* tmp = q.front();
                    q.pop();
                    if(tmp->left) q.push(tmp->left);
                    if(tmp->right) q.push(tmp->right);
                    if(i == size - 1) res.push_back(tmp->val);
                }
            }
        };
        bfs(root);
        return res;
    }
};