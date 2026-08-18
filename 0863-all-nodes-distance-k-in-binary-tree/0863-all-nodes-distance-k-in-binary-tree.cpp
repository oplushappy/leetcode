/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        auto buildParent = [&](auto &self, TreeNode * node, TreeNode * parent) {
            if(!node) return;
            parentMap[node] = parent;
            self(self, node->left, node);
            self(self, node->right, node);
        };
        buildParent(buildParent, root, nullptr);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);
        int dist = 0;
        
        while(!q.empty() && dist < k) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode * cur = q.front();
                q.pop();
                for(TreeNode * tmp : {cur->left, cur->right, parentMap[cur]}) {
                    if(tmp && !visited.count(tmp)){
                        visited.insert(tmp);
                        q.push(tmp);
                    }
                }
            }
            dist++;
        }
        vector<int> res;
        while(!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};