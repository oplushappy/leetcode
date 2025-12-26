class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        dfs(0, cur, 0, target, candidates);
        return res;
    }
    void dfs(int i, vector<int>& cur, int total, int target, vector<int>& candidates) {
        if(total == target) {
            res.push_back(cur);
            return;
        }
        
        if(i >= candidates.size() || total > target) {
            return;
        }

        cur.push_back(candidates[i]);
        dfs(i, cur, total + candidates[i], target, candidates);
        cur.pop_back();
        dfs(i + 1, cur, total, target, candidates);
    }
};