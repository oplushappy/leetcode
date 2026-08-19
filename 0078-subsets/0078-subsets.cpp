class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        int n = nums.size();
        auto backtrack = [&](auto self, int lower) {
            if(subset.size() > nums.size()) return;
            res.push_back(subset);
            for(int i = lower; i < n; i++) {
                subset.push_back(nums[i]);
                self(self, i + 1);
                subset.pop_back();
            }
        };
        backtrack(backtrack, 0);
        return res;
    }
};