class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        int n = candidates.size();
        auto backtrack = [&](auto &self, int pos, int sum) {
            if(sum == target) {
                res.push_back(comb);
                return;
            }

            if(sum > target) return;
            if(pos >= n) return;

            comb.push_back(candidates[pos]);
            self(self, pos, sum + candidates[pos]);
            comb.pop_back();

            self(self, pos + 1, sum);

            return;
        };

        backtrack(backtrack, 0, 0);
        return res;
    }
};